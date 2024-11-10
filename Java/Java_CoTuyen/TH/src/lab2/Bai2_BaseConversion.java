package lab2;

import java.util.Scanner;

public class Bai2_BaseConversion {

	// Hàm chuyển đổi từ hệ cơ số 10 sang hệ cơ số b
	public static String convertToBase(int decimalNumber, int base) {
		if (base < 2 || base > 36) {
			throw new IllegalArgumentException("Cơ số phải nằm trong khoảng từ 2 đến 36.");
		}

		String digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		if (decimalNumber == 0) {
			return "0";
		}

		String result = "";

		while (decimalNumber > 0) {
			int remainder = decimalNumber % base;
			result = digits.charAt(remainder) + result;
			decimalNumber /= base;
		}

		return result;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Nhập số ở hệ cơ số 10: ");
		int decimalNumber = scanner.nextInt();

		System.out.print("Nhập cơ số cần chuyển đổi (2-36): ");
		int base = scanner.nextInt();

		try {
			// Gọi hàm chuyển đổi và hiển thị kết quả
			String result = convertToBase(decimalNumber, base);
			System.out.println("Số " + decimalNumber + " ở hệ cơ số " + base + " là: " + result);
		} catch (IllegalArgumentException e) {
			// Xử lý lỗi khi cơ số không hợp lệ
			System.out.println(e.getMessage());
		}
		scanner.close();

	}
}
