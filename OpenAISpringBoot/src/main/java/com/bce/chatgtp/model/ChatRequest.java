package com.bce.chatgtp.model;

import java.util.List;

import lombok.Data;

@Data
public class ChatRequest {

	private String model;
	private List<Message> messages;
	private int n;
	private double temperature;

}