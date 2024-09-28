package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(urlPatterns = { "/session-login" })
public class Video16_SessionLogin extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");

		PrintWriter writer = resp.getWriter();
		writer.println("<form action='/DemoServlet/session-login' method='post'>");
		writer.println("Username: <input type='text' name='username' /> ");
		writer.println("Password: <input type='password' name='password' /> ");
		writer.println("<input type='submit' name='submit' /> ");
		writer.println("</form>");

		writer.close();
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();
		HttpSession httpSession = req.getSession();

		String username = req.getParameter("username");
		String password = req.getParameter("password");

		if (username.equals("duongpham26") && password.equals("123456")) {
			httpSession.setAttribute("username", username);
			resp.sendRedirect("/DemoServlet/welcome-session");
		} else {
			resp.sendRedirect("/DemoServlet/session-login");
		}

//		writer.println("Hello " + username + " " + password);

		writer.close();
	}
}
