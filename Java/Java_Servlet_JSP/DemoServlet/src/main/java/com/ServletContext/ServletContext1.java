package com.ServletContext;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = { "/servlet-context-1" })
public class ServletContext1 extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");

		PrintWriter writer = resp.getWriter();

		String jdbc = getServletContext().getInitParameter("jdbc");
		writer.println("Hello Duong Pham " + jdbc);
		getServletContext().setAttribute("name", "DuongPham");

	}
}
