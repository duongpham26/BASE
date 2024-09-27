package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = { "/add-user" })
public class PersonServlet extends HttpServlet {

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");

		PrintWriter writer = resp.getWriter();

		String name = req.getParameter("name");
		String age = req.getParameter("age");
		String address = req.getParameter("address");

		writer.println("Ten " + name + " Tuoi " + age + " Address " + address);
	}

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");

		PrintWriter writer = resp.getWriter();

		String name = req.getParameter("name");
		String age = req.getParameter("age");
		String address = req.getParameter("address");

		writer.println("Ten " + name + " Tuoi " + age + " Address " + address);
	}
}
