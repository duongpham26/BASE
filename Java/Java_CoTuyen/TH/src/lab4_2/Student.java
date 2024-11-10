package lab4_2;

public class Student extends Human {

	private String studentId;
	private Subject[] subjects;

	public Student() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Student(String fullName, String citizenID, String sex, String nationality, String studentId,
			Subject[] subjects) {
		super(fullName, citizenID, sex, nationality);
		this.studentId = studentId;
		this.subjects = subjects;
	}

	public String getStudentId() {
		return studentId;
	}

	public void setStudentId(String studentId) {
		this.studentId = studentId;
	}

	public Subject[] getSubjects() {
		return subjects;
	}

	public void setSubjects(Subject[] subjects) {
		this.subjects = subjects;
	}

	public double GPA() {
		int l = subjects.length;
		double sum = 0;
		for (int i = 0; i < l; i++) {
			sum += this.subjects[i].getMark();
		}
		return sum / l;
	}

	public static boolean validNumberOfSubject(int number) {
		if (number >= 1 && number <= 5) {
			return true;
		}
		System.out.println("Invalid Number of Subject");
		return false;
	}

}
