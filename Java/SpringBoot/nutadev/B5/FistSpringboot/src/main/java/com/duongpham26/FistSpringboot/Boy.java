package com.duongpham26.FistSpringboot;

import jakarta.annotation.PostConstruct;
import jakarta.annotation.PreDestroy;
import org.springframework.stereotype.Component;

//@Component
public class Boy {

    @PostConstruct
    public void init() {
        System.out.println("Boy init");
    }

    @PreDestroy
    public void destroy() {
        System.out.println("Boy destroy");
    }
}
