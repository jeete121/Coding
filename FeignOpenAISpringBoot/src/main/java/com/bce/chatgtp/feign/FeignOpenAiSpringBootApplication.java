package com.bce.chatgtp.feign;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableFeignClients
public class FeignOpenAiSpringBootApplication {

	public static void main(String[] args) {
		SpringApplication.run(FeignOpenAiSpringBootApplication.class, args);
	}

}
