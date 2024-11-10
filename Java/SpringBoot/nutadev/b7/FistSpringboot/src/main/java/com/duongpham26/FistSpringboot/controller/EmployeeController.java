package com.duongpham26.FistSpringboot.controller;

import com.duongpham26.FistSpringboot.entity.Employee;
import com.duongpham26.FistSpringboot.service.EmployeeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
public class EmployeeController {

    @Autowired
    private EmployeeService employeeService;

    @RequestMapping("/employee")
    public String employeeList(Model model) {
        List<Employee> employees = employeeService.getListEmployees();
        model.addAttribute("employeesList", employees);
        return "employee-view";
    }
}
