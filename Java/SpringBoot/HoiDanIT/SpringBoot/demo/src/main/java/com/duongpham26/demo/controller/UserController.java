package com.duongpham26.demo.controller;

import org.springframework.web.bind.annotation.RestController;

import com.duongpham26.demo.entity.User;
import com.duongpham26.demo.service.UserService;

import java.util.List;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
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

   @DeleteMapping("/user/delete/{id}") 
   public String deleteUser(@PathVariable("id") long id) {
      this.userService.handleDeleteUser(id);
      return "...";
   }

   @GetMapping("/user/get-user/{id}") 
   public User getUser(@PathVariable("id") long id) {
      User user = this.userService.handleGetUser(id);
      return user;
   }

   @GetMapping("/user/get-all-user")
   public List<User> getMethodName() {
      List<User> listUser = this.userService.handleGetAllUser();
       return listUser;
   }
   
   
}
