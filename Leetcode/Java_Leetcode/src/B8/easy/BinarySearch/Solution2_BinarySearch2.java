package B8.easy.BinarySearch;

public class Solution2_BinarySearch2 {
	public int search(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;
		int mid;
		while (left <= right) {
			if (right == left)
				mid = left;
			else
				mid = (right - left) * (target - nums[left]) / (nums[right] - nums[left]) + left;
			if (target == nums[mid]) {
				return mid;
			}
			if (target > nums[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		Solution2_BinarySearch2 s1 = new Solution2_BinarySearch2();
		System.out.println(s1.search(new int[] { -1, 0, 3, 5, 9, 12 }, 0));

	}
}
