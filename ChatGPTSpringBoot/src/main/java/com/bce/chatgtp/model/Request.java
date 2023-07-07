package com.bce.chatgtp.model;

import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.Data;

@Data
public class Request {

	private String model;
	private String prompt;
	@JsonProperty("max_tokens")
	private Integer maxTokens;
	private Double temperature;
	@JsonProperty("top_p")
	private Double topP;
}