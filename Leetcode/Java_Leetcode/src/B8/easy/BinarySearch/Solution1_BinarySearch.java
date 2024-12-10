package B8.easy.BinarySearch;

public class Solution1_BinarySearch {
	public int search(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;
		int mid;
		while (left <= right) {

			mid = (left + right) / 2;
			System.out.println(mid);
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
		Solution1_BinarySearch s1 = new Solution1_BinarySearch();
		System.out.println(s1.search(new int[] { -1, 0, 3, 5, 9, 12 }, 0));

	}
}
