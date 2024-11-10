package com.duongpham26.FistSpringboot.repository;

import com.duongpham26.FistSpringboot.entity.Employee;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public class EmployRepository {
    public List<Employee> getEmployeesFromDB() {
        return List.of(new Employee(1, "Pham Thanh Duong", 18),
                new Employee(2, "Duong 2", 19));
    }
}
