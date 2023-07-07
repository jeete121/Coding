package com.bce.chatgtp.service;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import com.bce.chatgtp.model.Request;
import com.bce.chatgtp.model.Response;

@Service
public class ChatGPTWithSpringBootService {

	private Logger log = LoggerFactory.getLogger(ChatGPTWithSpringBootService.class);

	@Value("${openAi.url.endpoint}")
	private String openAiEndpoint;

	@Autowired
	@Qualifier("customRestTemplate")
	private RestTemplate restTemplate;

	public Response submitOpenAiRequest(Request openAiRequest) {

		ResponseEntity<Response> restCallResponse = this.restTemplate.postForEntity(openAiEndpoint, openAiRequest,
				Response.class);

		if (HttpStatus.OK.equals(restCallResponse.getStatusCode())) {
			Response aiResponse = restCallResponse.getBody();
			log.info("OpenAi Response for command -- {} is ==>> {}", openAiRequest.getPrompt(), aiResponse);
			return aiResponse;
		} else
			return null;
	}
}