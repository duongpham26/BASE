package com.duongpham26.FistSpringboot.entity;

public class Employee {
    private long id;
    private String name;
    private int age;

    public Employee(long id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void setId(long id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String toString() {
        return "Employee [id=" + id + ", name=" + name + ", age=" + age + "]";
    }

}
