package com.bce.microservices.camelmicroservice2.routes;

import java.io.IOException;
import java.math.BigDecimal;
import java.security.Key;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.UnrecoverableKeyException;
import java.security.cert.CertificateException;

import org.apache.camel.builder.RouteBuilder;
import org.apache.camel.converter.crypto.CryptoDataFormat;
import org.apache.camel.model.dataformat.JsonLibrary;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.bce.microservices.camelmicroservice2.CurrencyExchange;

@Component
public class ActiveMqReceiverRouter extends RouteBuilder {

	@Autowired
	private MyCurrencyExchangeProcessor myCurrencyExchangeProcessor;

	@Autowired
	private MyCurrencyExchangeTransformer myCurrencyExchangeTransformer;

	@Override
	public void configure() throws Exception {
//		from("activemq:my-activemq-queue").unmarshal().json(JsonLibrary.Jackson, CurrencyExchange.class)
//				.bean(myCurrencyExchangeProcessor).bean(myCurrencyExchangeTransformer)
//				.to("log:received-message-from-active-mq");

		// JSON UNMARSHALING
//		from("activemq:my-activemq-queue").unmarshal().json(JsonLibrary.Jackson, CurrencyExchange.class)
//				.bean(myCurrencyExchangeTransformer).to("log:received-message-from-active-mq");

		// XML UNMARSHALING
//		from("activemq:my-activemq-xml-queue").unmarshal().jacksonxml(CurrencyExchange.class)
//				.to("log:received-message-from-active-mq");

		from("activemq:my-activemq-queue").unmarshal(createEncryptor()).to("log:received-message-from-active-mq");

		// from("activemq:split-queue").to("log:received-message-from-active-mq");

	}

	private CryptoDataFormat createEncryptor() throws KeyStoreException, IOException, NoSuchAlgorithmException,
			CertificateException, UnrecoverableKeyException {
		KeyStore keyStore = KeyStore.getInstance("JCEKS");
		ClassLoader classLoader = getClass().getClassLoader();
		keyStore.load(classLoader.getResourceAsStream("myDesKey.jceks"), "someKeystorePassword".toCharArray());
		Key sharedKey = keyStore.getKey("myDesKey", "someKeyPassword".toCharArray());

		CryptoDataFormat sharedKeyCrypto = new CryptoDataFormat("DES", sharedKey);
		return sharedKeyCrypto;
	}

}

@Component
class MyCurrencyExchangeProcessor {

	private Logger logger = LoggerFactory.getLogger(MyCurrencyExchangeProcessor.class);

	public void processMessage(CurrencyExchange currencyExchange) {
		logger.info("Do some processing with currencyExchange.getConversionMultiple() whose value is {}",
				currencyExchange.getConversionMultiple());
	}

}

@Component
class MyCurrencyExchangeTransformer {

	public CurrencyExchange processMessage(CurrencyExchange currencyExchange) {
		currencyExchange.setConversionMultiple(currencyExchange.getConversionMultiple().multiply(BigDecimal.TEN));
		return currencyExchange;
	}

}
