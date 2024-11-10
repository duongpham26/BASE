package com.duongpham26.FistSpringboot.service;

import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;

@Component
//@Primary
public class SmsService implements MessageService {
    @Override
    public void sendMessage(String message) {
        System.out.println("SMS " + message);
    }
}
