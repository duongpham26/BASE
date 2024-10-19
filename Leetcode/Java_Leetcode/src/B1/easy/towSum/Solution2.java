package B1.easy.towSum;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution2 {
	public int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			int cur = nums[i];
			int key = target - cur;
			System.out.println("key + " + key);
			if (map.containsKey(cur)) {
				return new int[] { map.get(cur), i };
			}
			map.put(key, i);
		}
		return new int[] {};
	}

	public static void main(String[] args) {
		Solution2 case2 = new Solution2();
		int[] arr = { 1, 2, -3, 4, 5 };
		int[] indies = case2.twoSum(arr, 6);
		System.out.println(Arrays.toString(indies));
	}
}
