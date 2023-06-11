package com.bce.microservices.camelmicroservice2.routes;

import org.apache.camel.builder.RouteBuilder;
import org.springframework.stereotype.Component;

@Component
public class KafkaReceiverRouter extends RouteBuilder {

	@Override
	public void configure() throws Exception {

		// from("kafka:myFirstTopic").to("log:received-message-from-kafka");
	}

}