package Tuan4;

import java.util.Scanner;

public class Test {
	private int n;
	private Student[] a;

	public Student nhap1SV() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Id : ");
		String id = scanner.nextLine();
		System.out.print("Name : ");
		String name = scanner.nextLine();
		System.out.print("Age : ");
		int age = scanner.nextInt();
		scanner.nextLine();
		System.out.print("Address : ");
		String address = scanner.nextLine();
		System.out.print("Average Point : ");
		float averagePoint = scanner.nextFloat();
		return new Student(id, name, age, address, averagePoint);
	}

	public void nhapDanhSach(int n) {
		this.a = new Student[n];
		for (int i = 0; i < n; i++) {
			System.out.println("\nNhap SV thu " + (i + 1) + " : ");
			this.a[i] = nhap1SV();
		}
	}

	void Input() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhap so hoc sinh: ");
		this.n = scanner.nextInt();
		nhapDanhSach(n);
	}

	public void HienThiDS() {
		System.out.println("----------------------------------------------------------------------");
		System.out.printf("%-10s %-20s %-5s %-20s %-15s%n", "ID", "Name", "Age", "Address", "Average Point");
		System.out.println("----------------------------------------------------------------------");
		for (int i = 0; i < this.n; i++) {
			Student s = this.a[i];
			s.display();
		}
		System.out.println("----------------------------------------------------------------------");
	}

	public static void main(String[] args) {
		Test test = new Test();
		test.Input();
		test.HienThiDS();
	}
}
