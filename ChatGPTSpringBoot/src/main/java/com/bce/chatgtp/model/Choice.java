package com.bce.chatgtp.model;

import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.Data;

@Data
public class Choice {

	private String text;
	private Integer index;
	@JsonProperty("finish_reason")
	private String finishReason;
}