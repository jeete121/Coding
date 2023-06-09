package com.bce.rabbitmq.producer.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.bce.rabbitmq.producer.service.RabbitMQSender;

@RestController
public class RabbitMQController {

	@Autowired
	private RabbitMQSender rabbitMQSender;

	@PostMapping(value = "/producer")
	public String producer(@RequestBody String message) {
		rabbitMQSender.send(message);
		return "Message sent to the RabbitMQ Successfully";
	}

}
