package B1.easy.towSum;

import java.util.Arrays;

public class Solution {
	public int[] twoSum(int[] nums, int target) {
		for (int i = 0; i < nums.length - 1; i++) {
			for (int j = i + 1; i < nums.length; j++) {
				if (nums[j] + nums[i] == target) {

					return new int[] { i, j };
				}
			}
		}
		return new int[] {};
	}

	public static void main(String[] args) {
		Solution case1 = new Solution();
		int[] arr = { 1, 2, 3, 4, 5 };
		int[] indies = case1.twoSum(arr, 4);
		System.out.println(Arrays.toString(indies));
	}
}
