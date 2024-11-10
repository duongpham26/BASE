<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<p>Thong tin nguoi dung la duongpham</p>
	<%int id =Integer.valueOf(request.getParameter("id"));  %>
	<p>id cua ban la: <%=id %> </p>
	
	<a href="logout.jsp">Dang xuat</a>
</body>
</html>