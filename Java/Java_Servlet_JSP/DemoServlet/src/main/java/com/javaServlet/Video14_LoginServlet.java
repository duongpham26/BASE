package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = { "/login" })
public class Video14_LoginServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");

		PrintWriter writer = resp.getWriter();
		writer.println("<form action='/DemoServlet/login' method='post' >");
		writer.println("UserName: <input type='text' name='username'/> ");
		writer.println("Password: <input type='password' name='password'/> ");
		writer.println("<input type='submit' value='submit' />");
		writer.println("<form />");

		writer.close();
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		String username = req.getParameter("username");
		String password = req.getParameter("password");
		if (username.equals("duongpham26") && password.equals("123456")) {
			Cookie cookie = new Cookie("username", username);
			cookie.setMaxAge(30);
			resp.addCookie(cookie);
			resp.sendRedirect("/DemoServlet/welcome");
		} else {
			resp.sendRedirect("/DemoServlet/login");
		}
//		PrintWriter writer = resp.getWriter();
//		writer.print(name + " " + password);
//		writer.close();
	}
}
