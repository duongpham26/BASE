package lab2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Bai3_StudentScores {

	// Hàm đọc điểm trung bình từ file
	public static ArrayList<Double> readScoresFromFile(String filename) {
		ArrayList<Double> scores = new ArrayList<>();
		try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
			String line;
			while ((line = reader.readLine()) != null) {
				try {
					double score = Double.parseDouble(line.trim());
					scores.add(score);
				} catch (NumberFormatException e) {
					System.out.println("Lỗi định dạng điểm: " + line);
				}
			}
		} catch (IOException e) {
			System.out.println("Lỗi đọc file: " + e.getMessage());
		}
		return scores;
	}

	// Hàm tính trung bình cộng điểm số
	public static double calculateAverage(ArrayList<Double> scores) {
		double sum = 0;
		for (double score : scores) {
			sum += score;
		}
		return sum / scores.size();
	}

	// Hàm sắp xếp mảng bằng thuật toán Selection Sort
	public static void selectionSort(ArrayList<Double> scores) {
		int n = scores.size();
		for (int i = 0; i < n - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < n; j++) {
				if (scores.get(j) < scores.get(minIndex)) {
					minIndex = j;
				}
			}
			// Hoán đổi giá trị nhỏ nhất với giá trị ở vị trí i
			double temp = scores.get(minIndex);
			scores.set(minIndex, scores.get(i));
			scores.set(i, temp);
		}
	}

	// Hàm ghi kết quả vào file mới
	public static void writeResultToFile(String filename, double average, ArrayList<Double> sortedScores) {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
			writer.write("Trung bình cộng điểm trung bình: " + average + "\n");
			writer.write("Điểm trung bình sau khi sắp xếp:\n");
			for (double score : sortedScores) {
				writer.write(score + "\n");
			}
		} catch (IOException e) {
			System.out.println("Lỗi ghi file: " + e.getMessage());
		}
	}

	public static void main(String[] args) {
		// Đọc điểm trung bình từ file
		String inputFilename = "diem_trung_binh.txt"; // File chứa điểm trung bình
		ArrayList<Double> scores = readScoresFromFile(inputFilename);

		if (scores.isEmpty()) {
			System.out.println("Không có điểm nào được đọc từ file.");
			return;
		}

		// Tính trung bình cộng
		double average = calculateAverage(scores);
		System.out.println("Trung bình cộng điểm trung bình: " + average);

		// Sắp xếp điểm trung bình bằng Selection Sort
		selectionSort(scores);
		System.out.println("Điểm trung bình sau khi sắp xếp: " + scores);

		// Ghi kết quả vào file mới
		String outputFilename = "ket_qua_sap_xep.txt";
		writeResultToFile(outputFilename, average, scores);
		System.out.println("Kết quả đã được ghi vào file " + outputFilename);
	}
}
