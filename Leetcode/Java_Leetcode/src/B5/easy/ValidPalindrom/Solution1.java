package B5.easy.ValidPalindrom;

public class Solution1 {
	public boolean isPalindrome(String s) {
		s = s.toLowerCase();
		s = s.replaceAll("[^a-z0-9]", "");
		int StringL = s.length();
		for (int i = 0; i < StringL; i++) {
			if (s.charAt(i) != s.charAt(StringL - 1 - i))
				return false;
		}
		return true;
	}

	public static void main(String[] args) {
		Solution1 s1 = new Solution1();

		System.out.println(s1.isPalindrome("pham,1.1,mahp"));
	}
}
