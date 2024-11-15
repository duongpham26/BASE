package com.duongpham26.LaptopShop.repository;

import org.springframework.data.repository.CrudRepository;

import com.duongpham26.LaptopShop.domain.User;

public interface UserRepository extends CrudRepository<User, Long> {
   User save(User user);
}
