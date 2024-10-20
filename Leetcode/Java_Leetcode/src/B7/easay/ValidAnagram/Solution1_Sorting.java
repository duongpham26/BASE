package B7.easay.ValidAnagram;

import java.util.Arrays;

public class Solution1_Sorting {

	public String Sort(String s) {
		char[] a = s.toCharArray();
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[j] < a[i]) {
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		return Arrays.toString(a);
	}

	public boolean isAnagram(String s, String t) {
		return Sort(s).equals(Sort(t));
	}

	public static void main(String[] args) {
		Solution1_Sorting s1 = new Solution1_Sorting();

		System.out.println(s1.isAnagram("listen", "sient"));
	}
}
