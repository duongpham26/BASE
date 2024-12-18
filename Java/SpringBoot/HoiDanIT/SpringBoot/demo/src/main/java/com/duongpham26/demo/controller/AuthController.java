package com.duongpham26.demo.controller;

import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.core.Authentication;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.duongpham26.demo.entity.dto.LoginDTO;

import jakarta.validation.Valid;

@RestController
public class AuthController {

   private final AuthenticationManagerBuilder authenticationManagerBuilder;

   public AuthController(AuthenticationManagerBuilder authenticationManagerBuilder) {
      this.authenticationManagerBuilder = authenticationManagerBuilder;
   }

   @PostMapping("/login")
   public ResponseEntity<LoginDTO> login(@Valid @RequestBody LoginDTO loginDTO) {
      UsernamePasswordAuthenticationToken authenticationToken = new UsernamePasswordAuthenticationToken(
         loginDTO.getUsername(),
         loginDTO.getPassword()
      );

      // xác thực người dùng -> viết hàm loadUserByUserName 
      Authentication authentication = authenticationManagerBuilder.getObject().authenticate(authenticationToken);
      System.out.println("Authentication : " + authentication);
      return ResponseEntity.ok().body(loginDTO);
   }
}
