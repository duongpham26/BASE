package B2.easy.MergeTwoSortedList;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution1 {
	public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
		ListNode dumy = new ListNode();
		ListNode current = dumy;

		while (list1 != null && list2 != null) {
			if (list1.val > list2.val) {
				current.next = list2;
				list2 = list2.next;
			} else {
				current.next = list1;
				list1 = list1.next;
			}
			current = current.next;
		}
		current.next = (list1 == null) ? list1 : list2;
		return dumy.next;
	}

	public static void main(String[] args) {
		Solution1 Solution1 = new Solution1();
		ListNode l1 = new ListNode(11, null);
		l1 = new ListNode(5, l1);
		l1 = new ListNode(4, l1);
		l1 = new ListNode(3, l1);
		l1 = new ListNode(2, l1);

		ListNode l2 = new ListNode(10, null);
		l2 = new ListNode(9, l2);
		l2 = new ListNode(6, l2);
		l2 = new ListNode(5, l2);
		l2 = new ListNode(3, l2);

		ListNode listSorted = Solution1.mergeTwoLists(l1, l2);
		while (listSorted.next != null) {
			System.out.println(listSorted.val);

		}
	}
}
