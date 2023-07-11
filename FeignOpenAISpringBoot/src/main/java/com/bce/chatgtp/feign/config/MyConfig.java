package com.bce.chatgtp.feign.config;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Configuration;

import lombok.Data;

@Configuration
@Data
public class MyConfig {
	
	@Value("${openai.api.key}")
	private String openaiApiKey;

}
