package com.javaServlet;

import java.io.IOException;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(urlPatterns = {"/test-request"})
public class RequestServletDemo extends HttpServlet{
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		// TODO Auto-generated method stub
		System.out.println("Phuong thuc request : " + req.getMethod());
		System.out.println("Context type : " + req.getContentType());
		System.out.println("Context path : " + req.getContextPath());
		System.out.println("Servlet name : " + req.getServerName());
		System.out.println("Servlet path : " + req.getServletPath());
		
//		Enumeration<String> keys = req.getHeaderNames();
		
//		while(keys.hasMoreElements()) {
//			String key = keys.nextElement();
//			System.out.println(req.getHeader(key)	);
//		}
	}
}
