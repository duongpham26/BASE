package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(urlPatterns = { "/welcome-session" })
public class Video16_WelcomSession extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();
		HttpSession httpsession = req.getSession();
		String name = "";
		name = (String) httpsession.getAttribute("username");
		if (name == null) {
			resp.sendRedirect("/DemoServlet/session-login");
		}

		writer.println("Hello " + name);
		writer.print("<br/> Logout: <a href='/DemoServlet/logout' > Logout </a>");
	}
}
