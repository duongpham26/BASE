package lab5;

public class Engineer extends Employee {

	private int WorkHoursPerDay;
	private int OverTimeHoursPerDay;

	public Engineer() {
		super();
	}

	public Engineer(String name, String staffID, int age, int WorkHoursPerDay, int OverTimeHoursPerDay) {
		super(name, staffID, age);
		this.WorkHoursPerDay = WorkHoursPerDay;
		this.OverTimeHoursPerDay = OverTimeHoursPerDay;
	}

	public int getWorkHoursPerDay() {
		return this.WorkHoursPerDay;
	}

	public void setWorkHoursPerDay(int workHoursPerDay) {
		this.WorkHoursPerDay = workHoursPerDay;
	}

	public int getOverTimeHoursPerDay() {
		return this.OverTimeHoursPerDay;
	}

	public void setOverTimeHoursPerDay(int overTimeHoursPerDay) {
		this.OverTimeHoursPerDay = overTimeHoursPerDay;
	}

	public static boolean validWorkHoursPerDay(int number) {
		if (number >= 0 && number <= 12) {
			return true;
		}
		System.out.println("Invalid WorkHoursPerDay");
		return false;
	}

	public double salary() {
		return this.OverTimeHoursPerDay * 2 * this.WorkHoursPerDay;
	}

}
