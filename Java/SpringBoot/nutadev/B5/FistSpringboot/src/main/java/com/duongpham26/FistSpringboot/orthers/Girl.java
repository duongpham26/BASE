package com.duongpham26.FistSpringboot.orthers;

import com.duongpham26.FistSpringboot.Boy;
import jakarta.annotation.PostConstruct;
import jakarta.annotation.PreDestroy;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Lazy;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

//@Lazy
@Scope("prototype")
@Component
public class Girl {
    @Autowired
    private Boy boy;
    public Girl() {
        System.out.println("Girl duoc khoi tao");
    }

    @PostConstruct
    public void init()   {
        System.out.println("Girl Post");
    }

    @PreDestroy
    public void destroy() {
        System.out.println("Girl Destroy");
    }
}
