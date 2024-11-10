package database;



import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class JDBCConnection {
	public static Connection getJDBCConnection() {
		final String url = "jdbc:mysql://localhost:3306/nhasach";
		final String user = "root";
		final String password = "123456";
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			return DriverManager.getConnection(url, user, password);			
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public static void closeConnection(Connection c) {
		if(c!= null) {
			try {
				c.close();
				System.out.println("Close connection successfully.");
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
