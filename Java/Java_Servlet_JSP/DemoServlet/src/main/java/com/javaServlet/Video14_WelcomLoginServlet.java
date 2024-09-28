package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = { "/welcome" })
public class Video14_WelcomLoginServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();

		String username = "";

		Cookie[] cookies = req.getCookies();
		if (cookies != null) {
			for (Cookie o : cookies) {
				if (o.getName().equals("username")) {
					username = o.getValue();
				}
			}
		}

		if (username.equals("")) {
			resp.sendRedirect("/DemoServlet/login");
		}
		writer.println("Welcom " + username);
	}
}
