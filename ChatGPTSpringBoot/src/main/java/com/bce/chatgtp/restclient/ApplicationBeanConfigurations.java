package com.bce.chatgtp.restclient;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.client.RestTemplate;

@Configuration
public class ApplicationBeanConfigurations {

	@Value("${personal.openai.api.token}")
	private String personalOpenAiToken;

	@Bean
	@Qualifier("customRestTemplate")
	public RestTemplate customRestTemplate() {
		RestTemplate restTemplate = new RestTemplate();
		restTemplate.getInterceptors().add((request, body, execution) -> {
			request.getHeaders().add("Authorization", "Bearer " + personalOpenAiToken);
			return execution.execute(request, body);
		});
		return restTemplate;
	}
}