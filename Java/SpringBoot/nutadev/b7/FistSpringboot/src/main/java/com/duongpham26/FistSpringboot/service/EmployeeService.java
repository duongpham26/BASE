package com.duongpham26.FistSpringboot.service;

import com.duongpham26.FistSpringboot.entity.Employee;
import com.duongpham26.FistSpringboot.repository.EmployRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class EmployeeService {

    @Autowired
    private EmployRepository employRepository;

    public List<Employee> getListEmployees() {
         return employRepository.getEmployeesFromDB();
    }
}
