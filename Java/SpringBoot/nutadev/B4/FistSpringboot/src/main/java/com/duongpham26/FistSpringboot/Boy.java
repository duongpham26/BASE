package com.duongpham26.FistSpringboot;


import com.fasterxml.jackson.databind.ObjectMapper;

public class Boy {

    private ObjectMapper objectMapper;

    public void useObjeactMapper() {
        System.out.println("ObjectMapper: " + objectMapper);
    }
}
