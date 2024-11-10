package lab4_2;

import java.util.Scanner;

public class Test {

	public static Employee employeeInput(Scanner scanner) {
		System.out.println("\n\nEmployee input:");
		System.out.print("Name : ");
		String name = scanner.nextLine();

//		scanner.nextLine();
		System.out.print("CitizenID : ");
		String citizenId = scanner.nextLine();

		System.out.print("Sex : ");
		String sex = scanner.nextLine();

		System.out.print("Nationality : ");
		String nationality = scanner.nextLine();

		System.out.print("Base Salary : ");
		int salary = scanner.nextInt();

		System.out.print("Over Time Hour : ");
		double overTimeHour = scanner.nextDouble();

		return new Employee(name, citizenId, sex, nationality, salary, overTimeHour);
	}

	public static void printEmployee(Employee e) {
		System.out.println("\n\nEmployee information:");
		boolean invalidCitizenID = Human.invalidCitizenID(e.getCitizenID());
		boolean invalidSex = Human.invalidSex(e.getSex());
		boolean invalidSalary = Employee.invalidSalary(e.getSalary());
		if (invalidCitizenID && invalidSex && invalidSalary) {
			System.out.println("Engineer Name: " + e.getFullName());
			System.out.println("CitizenID: " + e.getCitizenID());
			System.out.println("Sex: " + e.getSex());
			System.out.println("Nationality: " + e.getNationality());
			System.out.printf("Total Salary: %.2f\n", e.totalSalary());
		}
	}

	public static Student studentInput(Scanner scanner) {
		System.out.println("\n\nStudent input:");
		System.out.print("Name : ");
		String name = scanner.nextLine();

//		scanner.nextLine();
		System.out.print("CitizenID : ");
		String citizenId = scanner.nextLine();

		System.out.print("Sex : ");
		String sex = scanner.nextLine();

		System.out.print("Nationality : ");
		String nationality = scanner.nextLine();

		System.out.print("StudentID : ");
		String studentId = scanner.nextLine();

		System.out.print("Number of subjects : ");
		int numberOfSubjects = scanner.nextInt();
		scanner.nextLine();

		Subject[] subjects = new Subject[numberOfSubjects];

		for (int i = 0; i < numberOfSubjects; i++) {
			System.out.print("Name of subject " + (i + 1) + ": ");
			String nameSubject = scanner.nextLine();
			System.out.print("Mark of subject " + (i + 1) + ": ");
			double markSubject = scanner.nextDouble();
			scanner.nextLine();
			subjects[i] = new Subject(markSubject, nameSubject);
		}
		return new Student(name, citizenId, sex, nationality, studentId, subjects);
	}

	public static void printStudent(Student e) {
		System.out.println("\n\nEmployee information:");
		boolean invalidCitizenID = Human.invalidCitizenID(e.getCitizenID());
		boolean invalidSex = Human.invalidSex(e.getSex());
		boolean validNumberofSubject = Student.validNumberOfSubject(e.getSubjects().length);
		boolean validMark = true;
		for (int i = 0; i < e.getSubjects().length; i++) {
			validMark = Subject.validMarkOfSubject(e.getSubjects()[i].getMark());
			if (!validMark)
				break;

		}

		if (invalidCitizenID && invalidSex && validNumberofSubject && validMark) {
			System.out.println("Engineer Name: " + e.getFullName());
			System.out.println("CitizenID: " + e.getCitizenID());
			System.out.println("Sex: " + e.getSex());
			System.out.println("Nationality: " + e.getNationality());
			System.out.println("StudentID: " + e.getStudentId());
			System.out.printf("GPA: %.1f", e.GPA());
		}
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		Employee e = employeeInput(scanner);
		printEmployee(e);

//		Student s = studentInput(scanner);
//		printStudent(s);
		scanner.close();
	}

}
