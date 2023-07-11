package com.bce.email.service;

import com.bce.email.model.EmailDetails;
import com.bce.email.model.MailResponse;

public interface EmailService {

	MailResponse sendSimpleMail(EmailDetails details);

	MailResponse sendMailWithAttachment(EmailDetails details);
}
