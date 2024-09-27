package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = { "/form-user" })
public class FormPerson extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		// TODO Auto-generated method stub
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();
		writer.println("<form action='/DemoServlet/add-user' method='post'>");
		writer.println("Name: <input type='text' name='name'>");
		writer.println("Age: <input type='text' name='age'>");
		writer.println("Address: <input type='text' name='address'>");
		writer.println("<input type='submit' value='submit'>");
		writer.println("</form>");
	}
}
