package com.bce.chatgtp.controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import com.bce.chatgtp.model.ChatRequest;
import com.bce.chatgtp.model.ChatResponse;

@RestController
public class ChatController {

	private static Logger log = LoggerFactory.getLogger(ChatController.class);

	@Qualifier("openaiRestTemplate")
	@Autowired
	private RestTemplate restTemplate;

	@Value("${openai.api.url}")
	private String apiUrl;

	@PostMapping("/chat")
	public ChatResponse chat(@RequestBody ChatRequest chatRequest) {

		log.info("Calling an API of OpenAI");
		ChatResponse response = restTemplate.postForObject(apiUrl, chatRequest, ChatResponse.class);

		log.info("Response from OpenAI is {}", response);
		return response;
	}
}