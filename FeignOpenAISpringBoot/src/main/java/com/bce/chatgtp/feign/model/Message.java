package com.bce.chatgtp.feign.model;

import lombok.Data;

@Data
public class Message {

	private String role;
	private String content;

}