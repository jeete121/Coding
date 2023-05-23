package com.bce.config;

import org.apache.activemq.ActiveMQConnectionFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.jms.annotation.EnableJms;
import org.springframework.jms.config.DefaultJmsListenerContainerFactory;
import org.springframework.jms.core.JmsTemplate;

@Configuration
@EnableJms
public class JmsConsumerConfig {

	@Bean
	public ActiveMQConnectionFactory connectionFactory() {
		ActiveMQConnectionFactory connectionFactory = new ActiveMQConnectionFactory();
		connectionFactory.setBrokerURL("tcp://localhost:61616");
		connectionFactory.setUserName("admin");
		connectionFactory.setPassword("n3wp@ssw)rd");
		return connectionFactory;
	}

	@Bean
	public DefaultJmsListenerContainerFactory jmsListenerContainerFactory() {
		DefaultJmsListenerContainerFactory factory = new DefaultJmsListenerContainerFactory();
		factory.setConnectionFactory(connectionFactory());
		return factory;
	}

	@Bean
	public JmsTemplate jmsTemplate() {
		JmsTemplate jmsTemplate = new JmsTemplate(connectionFactory());
		return jmsTemplate;

	}

}
