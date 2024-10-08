<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<p>Hello JSP</p>
	<a href="profile.jsp?id=1">Click me!</a>
	<%
	int x = 10;
	int y = 20;
	int z = x + y;
	%>
	<h1><%=z%></h1>
</body>
</html>