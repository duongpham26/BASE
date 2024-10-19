package B1.easy.towSum;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution3 {
	public int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			map.put(nums[i], i);
		}
		for (int i = 0; i < nums.length; i++) {
			int complement = target - nums[i];
			if (map.containsKey(complement) && i != map.get(complement)) {
				return new int[] { map.get(complement), i };
			}
		}
		return new int[] {};
	}

	public static void main(String[] args) {
		Solution3 case2 = new Solution3();
		int[] arr = { 1, 2, -3, 4, 5 };
		int[] indies = case2.twoSum(arr, 10);
		System.out.println(Arrays.toString(indies));
	}
}
