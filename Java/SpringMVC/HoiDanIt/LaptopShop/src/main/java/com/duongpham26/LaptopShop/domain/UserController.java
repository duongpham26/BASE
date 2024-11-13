package com.duongpham26.LaptopShop.domain;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.duongpham26.LaptopShop.service.UserService;

// // Spring MVC
// @Controller
// public class UserController {
   
//    @RequestMapping("/")
//    public String getHomePage() {
//       return "from controller";
//    }
// }

// Rest API
@RestController
public class UserController {
   
   private UserService userService;

   public UserController(UserService userService) {
      this.userService = userService;
   }

   @GetMapping("/")
   public String getHomePage() {
      return this.userService.handleHello();
   }
}
