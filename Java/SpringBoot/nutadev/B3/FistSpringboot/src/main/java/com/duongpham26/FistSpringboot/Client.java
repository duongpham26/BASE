package com.duongpham26.FistSpringboot;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class Client {

    @Autowired
    private MessageService messageService;

//    public Client(MessageService messageService) {
//        this.messageService = messageService;
//    }

    //error
//    public void setMessageService(MessageService messageService) {
//        this.messageService = messageService;
//    }

    //    public Client(MessageService messageService) {
//        this.messageService = messageService;
//    }
    public void processMessage(String message) {
        messageService.sendMessage(message);
    }
}
