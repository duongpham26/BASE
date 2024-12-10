package lab5;

import java.util.Scanner;

public class Test {

	public static Engineer nhapThongTinEngineer(Scanner scanner) {
		System.out.println("\n\nEngineer input:");
		System.out.print("Name : ");
		String name = scanner.nextLine();

//		scanner.nextLine();
		System.out.print("StaffID : ");
		String staffID = scanner.nextLine();

		System.out.print("Age : ");
		int age = scanner.nextInt();

		System.out.print("WorkHoursPerDay : ");
		int WorkHoursPerDay = scanner.nextInt();

		System.out.print("OverTimeHoursPerDay : ");
		int OverTimeHoursPerDay = scanner.nextInt();

		return new Engineer(name, staffID, age, WorkHoursPerDay, OverTimeHoursPerDay);
	}

	public static Sales nhapThongTinSales(Scanner scanner) {
		System.out.println("\n\nEngineer input:");
		System.out.print("Name : ");
		String name = scanner.nextLine();

//		scanner.nextLine();
		System.out.print("StaffID : ");
		String staffID = scanner.nextLine();

		System.out.print("Age : ");
		int age = scanner.nextInt();

		System.out.print("NumberOfProduct : ");
		int NumberOfProduct = scanner.nextInt();

		System.out.print("Price : ");
		double Price = scanner.nextDouble();

		System.out.print("Interest : ");
		int Interest = scanner.nextInt();

		return new Sales(name, staffID, age, new Product(NumberOfProduct, Price, Interest));
	}

	public static void printEngineer(Engineer e) {
		System.out.println("\n\nEngineer information:");
		boolean validWorkHoursPerDay = Engineer.validWorkHoursPerDay(e.getWorkHoursPerDay());
		if (validWorkHoursPerDay) {
			System.out.println("Engineer Name: " + e.getName());
			System.out.println("StaffID: " + e.getStaffID());
			System.out.println("Age: " + e.getAge());
			System.out.println("WorkHoursPerDay: " + e.getWorkHoursPerDay());
			System.out.println("WorkHoursPerDay: " + e.getWorkHoursPerDay());
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		Engineer e1 = nhapThongTinEngineer(scanner);
		Sales s1 = nhapThongTinSales(scanner);
		printEngineer(e1);

		scanner.close();

	}
}
