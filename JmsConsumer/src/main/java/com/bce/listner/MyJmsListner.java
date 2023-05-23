package com.bce.listner;

import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.TextMessage;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.jms.annotation.JmsListener;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.stereotype.Component;

@Component
public class MyJmsListner {

	private Logger log = LoggerFactory.getLogger(MyJmsListner.class);

	@JmsListener(destination = "myQueue")
	@SendTo("myReceiver")
	public String consumeMessage(Message message) throws JMSException {

		log.info("Message Received");
		String messageData = null;
		if (message instanceof TextMessage) {
			log.info("Message is a type of TextMessage");
			TextMessage textMessage = (TextMessage) message;
			messageData = textMessage.getText();
		} else {
			log.error("Message is not the type of TextMessage");
		}
		log.info("Message Data is {}", messageData);
		return messageData;

	}

}
