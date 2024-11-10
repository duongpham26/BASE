package Tuan4;

public class Student {
	private String id;
	private String name;
	private int age;
	private String address;
	private float averagePoint;

	public Student(String id, String name, int age, String address, float averagePoint) {
		this.id = id;
		this.name = name;
		this.age = age;
		this.address = address;
		this.averagePoint = averagePoint;
	}

	public void setStudent(String id, String name, int age, String address, float averagePoint) {
		this.id = id;
		this.name = name;
		this.age = age;
		this.address = address;
		this.averagePoint = averagePoint;
	}

	public void setId(String id) {
		this.id = id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setAveragePoint(float averagePoint) {
		this.averagePoint = averagePoint;
	}

	public String getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	public String getAddress() {
		return address;
	}

	public float getAveragePoint() {
		return averagePoint;
	}

	public void display() {
		System.out.printf("%-10s %-20s %-5d %-20s %-15.2f%n", id, name, age, address, averagePoint);
	}
}
