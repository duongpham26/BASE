package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = { "/create-cookie" })
public class Video13_ServletCookie extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();

		writer.println("Hello");

		Cookie cookie = new Cookie("name", "Duong");
		cookie.setMaxAge(10);
		resp.addCookie(cookie);

		Cookie cookie2 = new Cookie("age", "22");
		cookie.setMaxAge(30);
		resp.addCookie(cookie2);
	}
}
