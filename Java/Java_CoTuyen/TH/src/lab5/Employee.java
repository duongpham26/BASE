package lab5;

public class Employee {

	private String Name;
	private String StaffID;
	private int Age;

	public Employee() {
	}

	public Employee(String name, String staffID, int Age) {
		this.Name = name;
		this.StaffID = staffID;
		this.Age = Age;
	}

	public String getName() {
		return this.Name;
	}

	public void setName(String name) {
		this.Name = name;
	}

	public String getStaffID() {
		return this.StaffID;
	}

	public void setStaffID(String staffID) {
		this.StaffID = staffID;
	}

	public int getAge() {
		return this.Age;
	}

	public void setAge(int Age) {
		this.Age = Age;
	}

}
