package com.javaServlet;

import java.io.PrintWriter;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;

@WebServlet(urlPatterns = { "/get-cookie" })
public class Video13_ServerGetCookie extends HttpServlet {
	protected void doGet(javax.servlet.http.HttpServletRequest req, javax.servlet.http.HttpServletResponse resp)
			throws javax.servlet.ServletException, java.io.IOException {
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();
		writer.println("Get cookie");

		for (Cookie o : req.getCookies()) {
			System.out.println(o.getName() + " " + o.getValue());
			writer.println(o.getName() + " " + o.getValue());
			if (o.getName().equals("age")) {
				o.setMaxAge(0);
				resp.addCookie(o);
			}
		}
	};
}
