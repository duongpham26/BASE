package com.duongpham26.FistSpringboot;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class FistSpringbootApplication {

	public static void main(String[] args) {
		ApplicationContext context =  SpringApplication.run(FistSpringbootApplication.class, args);

//		MessageService messageService = new EmailService();
//		Client client = new Client(messageService);
//		client.processMessage("Hello");

		// Lay doi tuong emailservice tu spring container
//		EmailService emailService = context.getBean(EmailService.class);
//		emailService.sendMessage("abc");

		// tự động injection emailservice vào trong client
	Client client = context.getBean(Client.class);
	client.processMessage("abc");

	}

}
