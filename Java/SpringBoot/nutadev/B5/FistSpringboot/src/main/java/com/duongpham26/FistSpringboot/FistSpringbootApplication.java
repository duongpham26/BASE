package com.duongpham26.FistSpringboot;

import com.duongpham26.FistSpringboot.orthers.Girl;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.ComponentScan;

@SpringBootApplication
//@SpringBootApplication(scanBasePackages = "com.duongpham26.FistSpringboot.orthers")
@ComponentScan("com.duongpham26.FistSpringboot.orthers")
public class FistSpringbootApplication {

	public static void main(String[] args) {

		ApplicationContext context =  SpringApplication.run(FistSpringbootApplication.class, args);
		System.out.println("Sau khi run app");
//		Boy boy = context.getBean(Boy.class);
		Girl girl = context.getBean(Girl.class);
		System.out.println("girl : " + girl);
//		System.out.println("boy : " + boy);
	}

}
