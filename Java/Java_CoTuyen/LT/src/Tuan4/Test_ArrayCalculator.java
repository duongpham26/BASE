package Tuan4;

public class Test_ArrayCalculator {
	public static void main(String[] args) {

		ArrayCalculator test = new ArrayCalculator();

		int[] intArray = { 6, 2, 3, 4, 5 };
		double[] doubleArray = { 4.3, 2.4, 3.6, 9.9, 5 };

		int maxInt = test.maxOfArray(intArray);
		double maxDouble = test.maxOfArray(doubleArray);
		int minInt = test.minOfArray(intArray);
		double minDouble = test.minOfArray(doubleArray);

		System.out.println("maxInt: " + maxInt);
		System.out.println("maxDouble: " + maxDouble);
		System.out.println("minInt: " + minInt);
		System.out.println("minDouble : " + minDouble);
	}
}
