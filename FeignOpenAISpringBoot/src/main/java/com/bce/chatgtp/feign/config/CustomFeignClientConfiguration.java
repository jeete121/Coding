package com.bce.chatgtp.feign.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import feign.okhttp.OkHttpClient;

@Configuration
public class CustomFeignClientConfiguration {
	@Bean
	public OkHttpClient client() {
		return new OkHttpClient();
	}
}