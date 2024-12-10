package com.duongpham26.demo.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import com.duongpham26.demo.service.IdInvalidException;


@RestController
public class HelloController {

    @GetMapping("/")
    public String getMethodName() {
        if(true) {
            // throw IdInvalidException("error");
        }
        return "hello0";
    }
}
