package com.duongpham26.LaptopShop.controller;

import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
// import org.springframework.web.bind.annotation.GetMapping;
// import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.duongpham26.LaptopShop.domain.User;
import com.duongpham26.LaptopShop.repository.UserRepository;
import com.duongpham26.LaptopShop.service.UserService;

// // Spring MVC
@Controller
public class UserController {
   
   private final UserService userService;

   public UserController(UserService userService) {
      this.userService = userService;
   }

   @RequestMapping("/")
   public String getHomePage(Model model) {
      List<User> arrUser = this.userService.getAllUsersByEmail("duong.pham2617@gmail.com");
      System.out.println("Array user : " + arrUser);
      String text = this.userService.handleHello();
      model.addAttribute("text", text);
      return "hello";
   }

   @RequestMapping("/admin/user")
   public String getUserPage(Model model) {
      List<User> users = this.userService.getAllUsers();
      model.addAttribute("users", users);
      System.out.println("Users : " + users);
      return "admin/user/table-user";
   }

   @RequestMapping("/admin/user/create")
   public String getUser(Model model) {
      model.addAttribute("newUser", new User());
      return "admin/user/create";
   }

   @RequestMapping(value = "admin/user/create", method = RequestMethod.POST)
      public String doAddUser(@ModelAttribute("newUser")User user, ModelMap model) {
      System.out.println("User " + user);

      User u = this.userService.handleSavaUser(user);
      String redirectUrl = "/admin/user";
      return "redirect:" + redirectUrl;
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
