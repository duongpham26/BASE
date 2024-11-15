package com.duongpham26.LaptopShop.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
// import org.springframework.web.bind.annotation.GetMapping;
// import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.duongpham26.LaptopShop.domain.User;
import com.duongpham26.LaptopShop.service.UserService;

// // Spring MVC
@Controller
public class UserController {
   
   private UserService userService;

   public UserController(UserService userService) {
      this.userService = userService;
   }

   @RequestMapping("/")
   public String getHomePage(Model model) {
      String text = this.userService.handleHello();
      model.addAttribute("text", text);
      return "hello";
   }

   @RequestMapping("/admin/user")
   public String getUserSer(Model model) {
      String text = this.userService.handleHello();
      model.addAttribute("text", text);
      return "admin/user/create";
   }

   @RequestMapping(value = "admin/user/create", method = RequestMethod.POST)
      public String doAddUser(@ModelAttribute("newUer")User user, ModelMap model) {
      System.out.println("User " + user);

      String text = this.userService.handleHello();
      model.addAttribute("text", text);
      return "hello";
  }
}

// Rest API
// @RestController
// public class UserController {
   
//    private UserService userService;

//    public UserController(UserService userService) {
//       this.userService = userService;
//    }

//    @GetMapping("/")
//    public String getHomePage() {
//       return this.userService.handleHello();
//    }
// }
