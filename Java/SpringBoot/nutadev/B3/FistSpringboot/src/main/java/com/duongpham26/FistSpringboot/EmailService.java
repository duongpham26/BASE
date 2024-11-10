package com.duongpham26.FistSpringboot;

import org.springframework.stereotype.Component;

@Component // spring container quản lí đối tượng EmailService
public class EmailService implements MessageService{
    public void sendMessage(String message) {
        System.out.println("Sending email " + message);
    }
}
