package dao;

import java.util.ArrayList;

public interface DAOInterface<T> {
	
	public int add(T t);
	
	public int delete(T t);
	
	public int update(T t);
	
	public ArrayList<T> sellectAll();
	
	public T selectById(T t);
	
	public ArrayList<T> sellectAllByCondition(String condition);
	
	
}
