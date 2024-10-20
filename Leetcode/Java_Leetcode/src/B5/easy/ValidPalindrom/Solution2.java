package B5.easy.ValidPalindrom;

public class Solution2 {
	public boolean isPalindrome(String s) {
		int first = 0;
		int last = s.length() - 1;

		while (first <= last) {
			char firstChar = s.charAt(first);
			char lastChar = s.charAt(last);
			if (!Character.isLetterOrDigit(firstChar))
				first++;
			else if (!Character.isLetterOrDigit(lastChar))
				last--;
			else {
				if (Character.toLowerCase(firstChar) != Character.toLowerCase(lastChar)) {
					return false;
				}
				first++;
				last--;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		Solution1 s1 = new Solution1();

		System.out.println(s1.isPalindrome("pham,2.1,mahp"));
	}

}
