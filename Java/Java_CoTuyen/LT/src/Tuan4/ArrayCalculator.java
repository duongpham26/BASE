package Tuan4;

public class ArrayCalculator {
	public int maxOfArray(int[] arr) {
		int max = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}

	public double maxOfArray(double[] arr) {
		double max = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}

	public int minOfArray(int[] arr) {
		int min = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] < min)
				min = arr[i];
		}
		return min;
	}

	public double minOfArray(double[] arr) {
		double min = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] < min)
				min = arr[i];
		}
		return min;
	}
}
