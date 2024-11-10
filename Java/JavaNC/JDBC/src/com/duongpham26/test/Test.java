package com.duongpham26.test;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

import com.duongpham26.connection.JDBCConnection;

public class Test {
	public static void main(String[] args) {
		Connection connection = JDBCConnection.getJDBCConnection();
		
		try {
			Statement statement = connection.createStatement();
			
			String slq =  "INSERT INTO SINHVIEN VALUES(2, \"DUONG 2\")";
			
			int check = statement.executeUpdate(slq);
			
			System.out.println("check: " + check);
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
			
		JDBCConnection.closeConnection(connection);
	}
}
