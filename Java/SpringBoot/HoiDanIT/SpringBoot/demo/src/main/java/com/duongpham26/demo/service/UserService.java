package com.duongpham26.demo.service;

import org.springframework.stereotype.Service;

import com.duongpham26.demo.entity.User;
import com.duongpham26.demo.repository.UserRepository;

@Service
public class UserService {

   private UserRepository userRepository;

   public UserService(UserRepository userRepository) {
      this.userRepository = userRepository;
   }

   public User handleCreateUser(User user) {
      return this.userRepository.save(user);
   }
   
}
