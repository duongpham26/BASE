package com.javaServlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(urlPatterns = { "/get-session" })
public class Video15_GetSessionId extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setContentType("text/html");
		PrintWriter writer = resp.getWriter();
		String sessionId = "";
		int sessionId1 = 0;
		HttpSession httpsession = req.getSession();
		Object o = httpsession.getAttribute("sessionId");
		Object o1 = httpsession.getAttribute("sessionId1");
		if (o != null) {
			sessionId = String.valueOf(o);
		} else {
			resp.sendRedirect("/DemoServlet/hello-session");
		}
		if (o1 != null) {
			sessionId1 = Integer.valueOf((String) o1);
		} else {
			resp.sendRedirect("/DemoServlet/hello-session");
		}
		writer.println("Hello " + sessionId + " " + sessionId1);
		writer.close();
	}
}
