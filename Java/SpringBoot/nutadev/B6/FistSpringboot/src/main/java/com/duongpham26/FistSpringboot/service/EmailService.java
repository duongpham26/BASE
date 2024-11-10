package com.duongpham26.FistSpringboot.service;

import org.springframework.stereotype.Component;

@Component("emailbean")
public class EmailService implements MessageService {

    @Override
    public void sendMessage(String message) {
        System.out.println("Email " + message);
    }
}
