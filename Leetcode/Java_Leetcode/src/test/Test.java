package test;

public class Test {
	public class Node {
		private Node next;
		private int data;

		Node(int data) {
			this.data = data;
		}
	}

//	private Node head;

	public void getDate() {
		Node temp = null;
		temp = new Node(1);
		temp.next = temp;

	}
}
