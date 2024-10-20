package B7.easay.ValidAnagram;

import java.util.Arrays;

public class Solution2_sorting_ArraySort {

	public boolean isAnagram(String s, String t) {

		char[] a = s.toCharArray();
		char[] b = t.toCharArray();
		Arrays.sort(a);
		Arrays.sort(b);
		return Arrays.equals(a, b);
	}

	public static void main(String[] args) {
		Solution1_Sorting s1 = new Solution1_Sorting();

		System.out.println(s1.isAnagram("listen", "slient"));
	}
}
