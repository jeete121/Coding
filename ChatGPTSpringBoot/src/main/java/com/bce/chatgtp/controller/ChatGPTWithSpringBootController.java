package com.bce.chatgtp.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.bce.chatgtp.model.Request;
import com.bce.chatgtp.model.Response;
import com.bce.chatgtp.service.ChatGPTWithSpringBootService;

@RestController
public class ChatGPTWithSpringBootController {

	@Autowired
	private ChatGPTWithSpringBootService chatGPTWithSpringBootService;

	@PostMapping("openAi/v1/springBoot")
	public Response submitOpenAiRequest(@RequestBody Request openAiRequest) {
		return chatGPTWithSpringBootService.submitOpenAiRequest(openAiRequest);
	}

}