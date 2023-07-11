package com.bce.email.service;

import java.io.File;

import javax.mail.MessagingException;
import javax.mail.internet.MimeMessage;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.FileSystemResource;
import org.springframework.http.HttpStatus;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.mail.javamail.MimeMessageHelper;
import org.springframework.stereotype.Service;

import com.bce.email.model.EmailDetails;
import com.bce.email.model.MailResponse;

@Service
public class EmailServiceImpl implements EmailService {

	private Logger logger = LoggerFactory.getLogger(EmailServiceImpl.class);

	@Autowired
	private JavaMailSender javaMailSender;

	@Value("${spring.mail.username}")
	private String sender;

	public MailResponse sendSimpleMail(EmailDetails details) {

		MailResponse mailResponse = new MailResponse();
		try {

			SimpleMailMessage mailMessage = new SimpleMailMessage();

			mailMessage.setFrom(sender);
			mailMessage.setTo(details.getRecipient());
			mailMessage.setText(details.getMsgBody());
			mailMessage.setSubject(details.getSubject());
			javaMailSender.send(mailMessage);
			logger.info("Successfully sent mail to {}", details.getRecipient());
			mailResponse.setDescription("Mail Sent Successfully...");
			mailResponse.setStatus(HttpStatus.OK.value());
			return mailResponse;
		} catch (Exception e) {
			logger.error("Error while sending mail to {}", details.getRecipient());
			mailResponse.setDescription("Error while Sending Mail - " + e.getMessage());
			mailResponse.setStatus(HttpStatus.INTERNAL_SERVER_ERROR.value());
			return mailResponse;
		}
	}

	public MailResponse sendMailWithAttachment(EmailDetails details) {

		MimeMessage mimeMessage = javaMailSender.createMimeMessage();
		MimeMessageHelper mimeMessageHelper;
		MailResponse mailResponse = new MailResponse();
		try {

			logger.info("Setting multipart as true for attachments to be send");

			mimeMessageHelper = new MimeMessageHelper(mimeMessage, true);
			mimeMessageHelper.setFrom(sender);
			mimeMessageHelper.setTo(details.getRecipient());
			mimeMessageHelper.setText(details.getMsgBody());
			mimeMessageHelper.setSubject(details.getSubject());

			logger.info("Adding the attchement");
			FileSystemResource file = new FileSystemResource(new File(details.getAttachment()));

			mimeMessageHelper.addAttachment(file.getFilename(), file);

			javaMailSender.send(mimeMessage);
			logger.info("Successfuly sent mail with attchment");
			mailResponse.setDescription("Mail Sent Successfully with attachment");
			mailResponse.setStatus(HttpStatus.OK.value());
			return mailResponse;
		} catch (MessagingException e) {
			logger.error("Error while sending mail to {} with attchment ", details.getRecipient());
			mailResponse.setDescription("Error while Sending Mail - " + e.getMessage());
			mailResponse.setStatus(HttpStatus.INTERNAL_SERVER_ERROR.value());
			return mailResponse;
		}
	}
}
