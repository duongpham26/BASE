package com.duongpham26.FistSpringboot.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
public class Client {


    @Autowired
    @Qualifier("emailbean")
    private MessageService messageService;

    public void processMessage(String message) {
        messageService.sendMessage(message);
    }

}
