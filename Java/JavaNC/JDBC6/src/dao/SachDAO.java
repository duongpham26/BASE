package dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import database.JDBCConnection;
import model.Sach;

public class SachDAO implements DAOInterface<Sach>{

	public static SachDAO getInstance() {
		return new SachDAO();
	}
	
	@Override
	public int add(Sach t) {
//		b1: tao ket noi
		Connection connection = JDBCConnection.getJDBCConnection();
		
		try {
//			b2
			Statement statement = connection.createStatement();
			String sql = "INSERT INTO SACH(ID, TENSACH, GIABAN, NAMXUATBAN)" +
					"VALUES('"+t.getId()+"','"+t.getTenSach()+"'," + t.getGiaBan()+","+t.getNamXuatBan()+")";
//			b3
			int ketqua = statement.executeUpdate(sql);
			
			System.out.println("Add successful!"); 
			
//			b4
			JDBCConnection.closeConnection(connection);
			return 1;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}

	@Override
	public int delete(Sach t) {
		Connection connection = JDBCConnection.getJDBCConnection();
		
		try {
//			b2
			Statement statement = connection.createStatement();
			
			String sql = "DELETE FROM SACH WHERE id = '" + t.getId() +"'";
			
			System.out.println(sql);
//			b3
			int ketqua = statement.executeUpdate(sql);
			
			System.out.println("Add successful!"); 
			
//			b4
			JDBCConnection.closeConnection(connection);
			return 1;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}


	@Override
	public int update(Sach t) {
		Connection connection = JDBCConnection.getJDBCConnection();
		
		try {
//			b2
			Statement statement = connection.createStatement();
			
			String sql = "UPDATE SACH" +
					" SET TENSACH='"+t.getTenSach()+"',"
							+ "GIABAN='" + t.getGiaBan()+"',"
							+ "NAMXUATBAN="+t.getNamXuatBan()
							+" WHERE id = '" + t.getId() +"'";
			
			System.out.println(sql);
//			b3
			int ketqua = statement.executeUpdate(sql);
			
			System.out.println("Add successful!"); 
			
			return 1;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {			
//			b4
			JDBCConnection.closeConnection(connection);
		}
		return 0;
	}

	@Override
	public ArrayList<Sach> selectAll() {
		
		ArrayList<Sach> listSach = new ArrayList<>();
		
		Connection connection = JDBCConnection.getJDBCConnection();
		
		try {
			Statement statement = connection.createStatement();
			String sql = "SELECT * FROM SACH";
			ResultSet resultSet = statement.executeQuery(sql);
			while(resultSet.next()) {
				String id = resultSet.getString("id");
				String tenSach = resultSet.getString("tenSach");
				float giaBan = resultSet.getFloat("giaBan");
				int namXuatBan = resultSet.getInt("namXuatBan");
				listSach.add(new Sach(id, tenSach, giaBan, namXuatBan)); 
			}
			return listSach;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			JDBCConnection.closeConnection(connection);			
		}
		return null;
	}

	@Override
	public Sach selectById(Sach t) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public ArrayList<Sach> sellectAllByCondition(String condition) {
		// TODO Auto-generated method stub
		return null;
	}
	
}
