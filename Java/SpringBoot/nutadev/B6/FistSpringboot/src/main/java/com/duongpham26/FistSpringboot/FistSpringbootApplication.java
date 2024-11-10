package com.duongpham26.FistSpringboot;

import com.duongpham26.FistSpringboot.service.Client;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class FistSpringbootApplication {

	public static void main(String[] args) {
		ApplicationContext context = SpringApplication.run(FistSpringbootApplication.class, args);
		Client client = context.getBean(Client.class);

		client.processMessage("HEllo");

	}

}
