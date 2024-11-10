package lab1;

import java.util.Scanner;

public class Bai2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập số hàng (1/2 chiều cao kim tự tháp): ");
		int n = scanner.nextInt();

		// In nửa trên của kim tự tháp
		for (int i = 1; i <= n; i++) {
			// In khoảng trắng
			for (int j = i; j < n; j++) {
				System.out.print(" ");
			}
			// In dấu sao
			for (int k = 1; k <= (2 * i - 1); k++) {
				System.out.print("*");
			}
			System.out.println();
		}

		// In nửa dưới của kim tự tháp
		for (int i = n - 1; i >= 1; i--) {
			// In khoảng trắng
			for (int j = n; j > i; j--) {
				System.out.print(" ");
			}
			// In dấu sao
			for (int k = 1; k <= (2 * i - 1); k++) {
				System.out.print("*");
			}
			System.out.println();
		}

		scanner.close();
	}
}
