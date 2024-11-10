<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	String name = request.getParameter("name");
	String password = request.getParameter("password");
	String phone = request.getParameter("phone");
	String about = request.getParameter("about");
	String favourite1 = request.getParameter("favourite1");
	String favourite2 = request.getParameter("favourite2");
	String favTotal = "";
	if(favourite1 != null) {
		favTotal += favourite1;
	}
	
	if(favourite2 != null) {
		favTotal += " - " + favourite2;
	}
	
	
	%>
	<table>
		<tr> 
			<td>Name </td>
			<td> <%= name %></td>
		</tr>
		<tr> 
			<td>Password </td>
			<td> <%= password %></td>
		</tr>
		<tr> 
			<td>Phone </td>
			<td> <%= phone %></td>
		</tr>
		<tr> 
			<td>About </td>
			<td> <%= about %></td>
		</tr>
		<tr> 
			<td>Favourite </td>
			<td> <%= favTotal %></td>
		</tr>

	</table>
</body>
</html>