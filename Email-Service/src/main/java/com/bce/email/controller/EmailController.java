package com.bce.email.controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.bce.email.model.EmailDetails;
import com.bce.email.model.MailResponse;
import com.bce.email.service.EmailService;

@RestController
public class EmailController {

	private Logger logger = LoggerFactory.getLogger(EmailController.class);

	@Autowired
	private EmailService emailService;

	@PostMapping("/sendMail")
	public ResponseEntity<MailResponse> sendMail(@RequestBody EmailDetails details) {
		logger.info(" Sending a simple Email to {}", details.getRecipient());
		MailResponse mailResponse = emailService.sendSimpleMail(details);

		if (mailResponse.getStatus() == HttpStatus.OK.value())
			return new ResponseEntity<MailResponse>(mailResponse, HttpStatus.OK);
		return new ResponseEntity<MailResponse>(mailResponse, HttpStatus.INTERNAL_SERVER_ERROR);

	}

	@PostMapping("/sendMailWithAttachment")
	public ResponseEntity<MailResponse> sendMailWithAttachment(@RequestBody EmailDetails details) {

		logger.info("Sending email with attachment to {}", details.getRecipient());

		MailResponse mailResponse = emailService.sendMailWithAttachment(details);
		if (mailResponse.getStatus() == HttpStatus.OK.value())
			return new ResponseEntity<MailResponse>(mailResponse, HttpStatus.OK);
		return new ResponseEntity<MailResponse>(mailResponse, HttpStatus.INTERNAL_SERVER_ERROR);
	}
}
