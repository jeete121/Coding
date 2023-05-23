package com.bce.config;

import org.apache.activemq.ActiveMQConnectionFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.jms.core.JmsTemplate;

@Configuration
public class JmsProducerConfig {

	@Bean
	public ActiveMQConnectionFactory connectionFactory() {
		ActiveMQConnectionFactory connectionFactory = new ActiveMQConnectionFactory();
		connectionFactory.setBrokerURL("tcp://localhost:61616");
		connectionFactory.setUserName("admin");
		connectionFactory.setPassword("n3wp@ssw)rd");
		return connectionFactory;
	}

	@Bean
	public JmsTemplate jmsTemplate() {
		JmsTemplate jmsTemplate = new JmsTemplate(connectionFactory());
		return jmsTemplate;

	}

}
