package lab4_2;

public class Subject {

	private double Mark;
	private String name;

	public Subject() {
		// TODO Auto-generated constructor stub
	}

	public Subject(double mark, String name) {
		Mark = mark;
		this.name = name;
	}

	public double getMark() {
		return Mark;
	}

	public void setMark(double mark) {
		Mark = mark;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public static boolean validMarkOfSubject(double mark) {
		if (mark >= 0 && mark <= 10) {
			return true;
		}
		System.out.println("Invalid Mark Of Subject");
		return false;
	}
}
