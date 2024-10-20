package B7.easay.ValidAnagram;

public class Solution3_HashMap_Array {
	public boolean isAnagram(String s, String t) {
		int[] count = new int[26];
		for (char x : s.toCharArray()) {
			count[x - 'a']++;
		}
		for (char x : s.toCharArray()) {
			count[x - 'a']--;
		}

		for (int val : count) {
			if (val != 0) {
				return false;
			}
		}
		return true;
	}
}
