package lab7_1;

import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Bai1 {
	public static void main(String[] args) {
		try {
			// Mở file để ghi
			FileOutputStream fos = new FileOutputStream("input.txt");
			PrintWriter writer = new PrintWriter(fos);

			// Dữ liệu mảng 2 chiều
			ArrayList<ArrayList<Integer>> arrayList2D = new ArrayList<>();
			arrayList2D.add(new ArrayList<>(Arrays.asList(41, 77, 74, 22, 44))); // Line 1
			arrayList2D.add(new ArrayList<>(Arrays.asList(12))); // Line 2
			arrayList2D.add(new ArrayList<>(Arrays.asList(37, 34, 36, 52))); // Line 3
			arrayList2D.add(new ArrayList<>()); // Line 4 (hàng trống)
			arrayList2D.add(new ArrayList<>(Arrays.asList(20, 22, 23))); // Line 5

			// Ghi số lượng hàng vào file
			writer.println(arrayList2D.size());

			// Ghi dữ liệu từng hàng vào file
			for (ArrayList<Integer> row : arrayList2D) {
				writer.print(row.size() + " ");
				for (int value : row) {
					writer.print(value + " ");
				}
				writer.println();
			}

			// Dữ liệu truy vấn (Queries)
			int[][] queries = { { 1, 3, 2 }, // Truy vấn 1: Line 1, từ phần tử thứ 3, lấy 2 phần tử
					{ 3, 4, 1 }, // Truy vấn 2: Line 3, từ phần tử thứ 4, lấy 1 phần tử
					{ 3, 1, 3 }, // Truy vấn 3: Line 3, từ phần tử thứ 1, lấy 3 phần tử
					{ 4, 3, 1 }, // Truy vấn 4: Line 4, từ phần tử thứ 3, lấy 1 phần tử (hàng trống -> ERROR)
					{ 5, 2, 3 } // Truy vấn 5: Line 5, từ phần tử thứ 2, lấy 3 phần tử (không đủ -> ERROR)
			};

			// Ghi số lượng truy vấn vào file
			writer.println(queries.length);

			// Ghi các truy vấn vào file
			for (int[] query : queries) {
				writer.println(query[0] + " " + query[1] + " " + query[2]);
			}

			// Đóng file
			writer.close();
			fos.close();

			System.out.println("Dữ liệu đã được ghi vào file input.txt!");

		} catch (Exception e) {
			System.out.println("ERROR: " + e.getMessage());
		}
	}
}
