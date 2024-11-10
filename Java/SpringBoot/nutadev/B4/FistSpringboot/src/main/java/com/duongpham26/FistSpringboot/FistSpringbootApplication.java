package com.duongpham26.FistSpringboot;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class FistSpringbootApplication {

	public static void main(String[] args) {
		ApplicationContext context =  SpringApplication.run(FistSpringbootApplication.class, args);
		Boy boy = context.getBean(Boy.class);
		System.out.println(boy);

//		boy.useObjeactMapper();
	}
}
