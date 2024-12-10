package Test;

public class Test {
	public static int max(int[] a) {
		if (a.length <= 1)
			return 0;
		int max1 = a[0];
		int max2 = a[0];
		for (int i = 1; i < a.length; i++) {
			if (a[i] > max1) {

				max2 = max1;
				max1 = a[i];
			}
		}
		if (max2 == max1)
			return 0;
		return max2;
	}

	public static void main(String[] args) {
		int a[] = { 5, 5, 1 };
		System.out.println(max(a));
	}
}
