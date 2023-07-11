package com.bce.chatgtp.feign.feigninterface;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.bce.chatgtp.feign.config.CustomFeignClientConfiguration;
import com.bce.chatgtp.feign.model.ChatRequest;
import com.bce.chatgtp.feign.model.ChatResponse;

@FeignClient(name = "${app.feign.config.name}", url = "${openai.api.url}", configuration = CustomFeignClientConfiguration.class)
public interface OpenAIFeignClientService {

	@RequestMapping(method = RequestMethod.POST)
	ChatResponse callOpenAIFeign(@RequestBody ChatRequest chatRequest,
			@RequestHeader(value = "Authorization", required = true) String authorizationHeader);
}