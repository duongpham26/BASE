package lab7_1;

import java.util.Arrays;

public class Bai2 {
	public static void main(String[] args) {
		// Tạo mảng 50 số nguyên ngẫu nhiên từ 0-100
		int[] arr = createRandomArray(50, 0, 100);

		System.out.println("Mảng ngẫu nhiên:");
		System.out.println(Arrays.toString(arr));

		// 1. Tìm kiếm và in ra vị trí các số trùng nhau
		findAndPrintDuplicates(arr);

		// 2. Tính tổng các số nguyên nhỏ hơn 50
		int sum = sumLessThan(arr, 50);
		System.out.println("\nTổng các số nhỏ hơn 50: " + sum);

		// 3. Sắp xếp mảng tăng dần
		sortAndPrintArray(arr);

		// 4. Tìm số nguyên hoàn hảo
		printNumbersWithMostDivisors(arr);
	}

	// Hàm tạo mảng ngẫu nhiên
	private static int[] createRandomArray(int size, int min, int max) {
		int[] arr = new int[size];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = (int) (Math.random() * (max - min + 1)) + min;
		}
		return arr;
	}

	// Hàm tìm và in ra các số trùng nhau trong mảng
	private static void findAndPrintDuplicates(int[] arr) {
		System.out.println("\nCác số trùng nhau và vị trí:");
		boolean hasDuplicates = false;

		for (int i = 0; i < arr.length; i++) {
			boolean isDuplicate = false;
			StringBuilder positions = new StringBuilder(i + " ");

			for (int j = i + 1; j < arr.length; j++) {
				if (arr[i] == arr[j]) {
					isDuplicate = true;
					positions.append(j).append(" ");
				}
			}

			if (isDuplicate) {
				System.out.println(arr[i] + ": " + positions);
				hasDuplicates = true;
			}
		}

		if (!hasDuplicates) {
			System.out.println("Không có số trùng nhau trong mảng!");
		}
	}

	// Hàm tính tổng các số nhỏ hơn giá trị giới hạn
	private static int sumLessThan(int[] arr, int limit) {
		int sum = 0;
		for (int num : arr) {
			if (num < limit) {
				sum += num;
			}
		}
		return sum;
	}

	// Hàm sắp xếp mảng tăng dần và in ra
	private static void sortAndPrintArray(int[] arr) {
		Arrays.sort(arr);
		System.out.println("\nMảng sau khi sắp xếp tăng dần:");
		System.out.println(Arrays.toString(arr));
	}

	private static void printNumbersWithMostDivisors(int[] arr) {
		int[] divisorCount = new int[arr.length]; // Mảng lưu số lượng các số chia hết cho mỗi số

		// Duyệt qua từng số trong mảng
		for (int i = 0; i < arr.length; i++) {
			int count = 0;

			// Kiểm tra các số khác trong mảng xem có chia hết cho arr[i] hay không
			for (int j = 0; j < arr.length; j++) {
				if (arr[j] != 0 && arr[i] != 0) {
					if (i != j && arr[i] % arr[j] == 0) { // Không tính chính nó
						count++;
					}
				}
			}
			divisorCount[i] = count;
		}

		// Tìm số lượng chia hết lớn nhất
		int maxDivisibleCount = 0;
		for (int i = 0; i < divisorCount.length; i++) {
			if (divisorCount[i] > maxDivisibleCount) {
				maxDivisibleCount = divisorCount[i];
			}
		}

		// In ra các số chia hết cho nhiều số nhất
		System.out.println("\nCác số chia hết cho nhiều số khác nhất:");
		for (int i = 0; i < arr.length; i++) {
			if (divisorCount[i] == maxDivisibleCount) {
				System.out.print(arr[i] + " ");
			}
		}
	}
}
