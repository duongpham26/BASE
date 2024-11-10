package lab4_2;

public class Employee extends Human {

	private int salary;

	private double overTimeHour;

	public Employee() {
		super();
	}

	public Employee(String fullName, String citizenID, String sex, String nationality, int salary,
			double overTimeHour) {
		super(fullName, citizenID, sex, nationality);
		this.salary = salary;
		this.overTimeHour = overTimeHour;
	}

	public int getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public double getOverTimeHour() {
		return overTimeHour;
	}

	public void setOverTimeHour(double overTimeHour) {
		this.overTimeHour = overTimeHour;
	}

	public double totalSalary() {
		return this.salary + (this.salary / (260) * 2 * this.overTimeHour);
	}

	public static boolean invalidSalary(int salary) {
		if (salary < 1000) {
			System.out.println("Invalid Salary");
			return false;
		}
		return true;
	}

}
