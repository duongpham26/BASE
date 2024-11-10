package com.duongpham26.FistSpringboot.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class EmployeeController {

    @RequestMapping("/employee")
    public String employeeList() {
        return "employee-view";
    }
}
