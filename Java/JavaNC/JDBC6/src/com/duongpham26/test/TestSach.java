package com.duongpham26.test;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import dao.SachDAO;
import database.JDBCConnection;
import model.Sach;

public class TestSach {
	public static void main(String[] args) {
		Sach sach = new Sach("LTJV", "Lap Trinh Java",5000, 2012);
		
//		for(int i = 0; i < 10; i++) {
//			Sach sach2 = new Sach("LT" + i, "Lap Trinh " + i, 5001, 2010);
//			SachDAO.getInstance().update(sach2);
//		}
//		
		Sach sach2 = new Sach("LT" + 9, "Lap Trinh " + 1, 5001, 2024);
//		SachDAO.getInstance().delete(sach2);
		
		ArrayList<Sach> lSach = SachDAO.getInstance().selectAll();		
		for(Sach s: lSach) {
			System.out.println(s);
		}
	}
}
