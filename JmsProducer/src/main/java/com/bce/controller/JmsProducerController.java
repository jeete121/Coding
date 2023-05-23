package com.bce.controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jms.core.JmsTemplate;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class JmsProducerController {

	private Logger log = LoggerFactory.getLogger(JmsProducerController.class);

	@Autowired
	private JmsTemplate jmsTemplate;

	@PostMapping("/produce")
	public void produceMessage(@RequestBody String message) {

		try {
			jmsTemplate.convertAndSend("myQueue", message);
			log.info("Successfully published message to jms queue");
		} catch (Exception e) {
			log.error("Error while publishing to jms queue");
		}
	}

}
