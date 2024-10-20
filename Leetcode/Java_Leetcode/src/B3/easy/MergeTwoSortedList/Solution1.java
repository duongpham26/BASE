package B3.easy.MergeTwoSortedList;

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

	}
}
