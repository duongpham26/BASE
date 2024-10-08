package com.ServletFilter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
import javax.servlet.annotation.WebInitParam;

@WebFilter(urlPatterns = { "/create-cookie" }, initParams = { @WebInitParam(name = "count", value = "100") })
public class Video18_Logger implements Filter {

	private int count;

	@Override
	public void destroy() {

	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
//		System.out.println("Filter 1");
//		chain.doFilter(request, response); // trả về đích hoặc filter tiếp theo
//		response.setContentType("text/plain");
		count++;
		System.out.println(count);

	}

	@Override
	public void init(FilterConfig filterConfig) throws ServletException {
		String c = filterConfig.getInitParameter("count");
		if (c != null)
			count = Integer.valueOf(c);
	}
}
