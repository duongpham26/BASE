package com.duongpham26.demo.controller;

import org.springframework.web.bind.annotation.RestController;

import com.duongpham26.demo.entity.User;
import com.duongpham26.demo.service.UserService;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;


@RestController
public class UserController {
   
   private final UserService userService;

   public UserController(UserService userService) {
      this.userService = userService;
   }

   @PostMapping("/user/create")
   public User createNewUser(@RequestBody User newUser) {
      User user = this.userService.handleCreateUser(newUser);
      return user;
   }
   
}
