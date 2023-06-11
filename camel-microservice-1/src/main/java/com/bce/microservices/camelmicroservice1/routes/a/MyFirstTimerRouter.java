package com.bce.microservices.camelmicroservice1.routes.a;

import java.time.LocalDateTime;

import org.apache.camel.Exchange;
import org.apache.camel.Processor;
import org.apache.camel.builder.RouteBuilder;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

//@Component
public class MyFirstTimerRouter extends RouteBuilder {

	@Autowired
	private GetCurrentTimeBean getCurrentTimeBean;

	@Autowired
	private SimpleLoggingProcessingComponent loggingComponent;

	@Override
	public void configure() throws Exception {

		// timer //endpoints
		// transformation
		// log //endpoints
		// from("timer:first-timer").to("log:first-timer"); //null body
		// from("timer:first-timer").transform().constant("My Constant
		// Message").to("log:first-timer"); // contant message

		// from("timer:first-timer").transform().constant("Time now is " +
		// LocalDateTime.now()).to("log:first-timer"); //timer messages

		// from("timer:first-timer").bean("getCurrentTimeBean").to("log:first-timer");

		// from("timer:first-timer").bean(getCurrentTimeBean).to("log:first-timer");

		// from("timer:first-timer").bean(getCurrentTimeBean,
		// "getCurrentTime").to("log:first-timer");

//		from("timer:first-time").log("${body}").transform().constant("My Constant Message").log("${body}")
//				.bean(getCurrentTimeBean).log("${body}");]

		// Processing
		// Transformation
//		from("timer:first-time").log("${body}").transform().constant("My Constant Message").log("${body}")
//				.bean(loggingComponent).log("${body}");

//		from("timer:first-time").log("${body}").transform().constant("My Constant Message").log("${body}")
//				.process(new SimpleLoggingProcessor()).log("${body}");
	}

}

@Component
class GetCurrentTimeBean {
	public String getCurrentTime() {
		return "Time now is " + LocalDateTime.now();

	}
}

//@Component
class SimpleLoggingProcessingComponent {

	private Logger logger = LoggerFactory.getLogger(SimpleLoggingProcessingComponent.class);

	public void process(String message) {
		logger.info("SimpleLoggingProcessingComponent {}", message);

	}
}

class SimpleLoggingProcessor implements Processor {

	private Logger logger = LoggerFactory.getLogger(SimpleLoggingProcessor.class);

	@Override
	public void process(Exchange exchange) throws Exception {
		logger.info("SimpleLoggingProcessor {}", exchange.getMessage().getBody());

	}

}
