<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h2>Add User</h2>
	<form action="viewUser.jsp">
		<input name="name" type="text" placeholder="Ten nguoi dung"> 
		<input name="password" type="text" placeholder="Mat khau nguoi dung">
		<input name="phone" type="text" placeholder="So dien thoai">
		<textarea rows="3" cols="25" name="about" placeholder="Gioi thieu"></textarea>
		<input name="favourite1" type="checkbox" value="Xem phim"> Xem phim
		<input name="favourite2" type="checkbox" value="Nghe nhac"> Nghe nhac
		<input type="submit" value="them">
	</form>
</body>
</html>