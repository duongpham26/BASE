package com.duongpham26.demo.service;

import java.util.List;

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

   public void handleDeleteUser(long id) {
      this.userRepository.deleteById(id);
   }

   public User handleGetUser(long id) {
      return this.userRepository.findOneById(id);
   }

   public List<User> handleGetAllUser() {
      return this.userRepository.findAll();
   }

   
   
}
