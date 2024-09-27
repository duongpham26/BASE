package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//@WebServlet(urlPatterns = { "/test-config" }, initParams = { @WebInitParam(name = "name", value = "Java") })
public class ConfigServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String name = super.getServletConfig().getInitParameter("name");
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();
		writer.println("Xin chao " + name);
	}

}
