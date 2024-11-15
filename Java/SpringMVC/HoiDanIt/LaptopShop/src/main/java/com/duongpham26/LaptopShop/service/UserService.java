package com.duongpham26.LaptopShop.service;

import org.springframework.stereotype.Service;

import com.duongpham26.LaptopShop.domain.User;
import com.duongpham26.LaptopShop.repository.UserRepository;

@Service
public class UserService {
   
   private UserRepository userRepository;

   public UserService(UserRepository userRepository) {
      this.userRepository = userRepository;
   }

   public String handleHello() {
      return "Hello from service";
   }

   public User handleSavaUser(User user) {
      return this.userRepository.save(user);
   }
}
