package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(urlPatterns = {"/test-response"})
public class ResponseServletDemo extends HttpServlet{
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		
		resp.setContentType("text/html"); // text/plain => trả về html; text/html => biên dich html 
		
		PrintWriter wrinter = resp.getWriter();
		wrinter.println("<h1>Hello</h1>");
		
		resp.addCookie(new Cookie("a", "aa"));
		resp.addHeader("b", "bb");
		resp.sendError(200);
		
		
		
		
//		Enumeration<String> keys = req.getHeaderNames();
		
//		while(keys.hasMoreElements()) {
//			String key = keys.nextElement();
//			System.out.println(req.getHeader(key)	);
//		}
	}
}
