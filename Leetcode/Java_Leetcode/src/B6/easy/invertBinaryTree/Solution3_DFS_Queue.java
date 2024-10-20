package B6.easy.invertBinaryTree;

import java.util.LinkedList;
import java.util.Queue;

public class Solution3_DFS_Queue {
	public TreeNode invertTree(TreeNode root) {
		if (root == null) {
			return null;
		}
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			final TreeNode node = queue.poll();
			final TreeNode left = node.left;
			node.left = node.right;
			node.right = left;
			if (node.left != null) {
				queue.offer(node.left);
			}
			if (node.right != null) {
				queue.offer(node.right);
			}
		}
		return root;
	}
}
