package com.bce.chatgtp.feign.controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.bce.chatgtp.feign.config.MyConfig;
import com.bce.chatgtp.feign.feigninterface.OpenAIFeignClientService;
import com.bce.chatgtp.feign.model.ChatRequest;
import com.bce.chatgtp.feign.model.ChatResponse;

@RestController
public class ChatController {

	private static Logger log = LoggerFactory.getLogger(ChatController.class);

	@Autowired
	private OpenAIFeignClientService openAIFeignClientService;

	@Autowired
	private MyConfig myConfig;

	@PostMapping("/chat/feign")
	public ChatResponse chat(@RequestBody ChatRequest chatRequest) {

		log.info("Calling an API of OpenAI");
		ChatResponse response = openAIFeignClientService.callOpenAIFeign(chatRequest, myConfig.getOpenaiApiKey());
		log.info("Response from OpenAI is {}", response);
		return response;
	}
}