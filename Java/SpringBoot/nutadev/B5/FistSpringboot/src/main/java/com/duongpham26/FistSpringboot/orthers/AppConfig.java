package com.duongpham26.FistSpringboot.orthers;

import com.duongpham26.FistSpringboot.Boy;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;

@Configuration
public class AppConfig {
    @Bean
    @Scope("prototype")
    public Boy boy() {
        return new Boy();
    }
}
