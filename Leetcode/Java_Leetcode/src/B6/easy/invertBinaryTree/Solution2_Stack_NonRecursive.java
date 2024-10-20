package B6.easy.invertBinaryTree;

import java.util.Stack;

public class Solution2_Stack_NonRecursive {
	public TreeNode invertTree(TreeNode root) {
		if (root == null) {
			return null;
		}
		Stack<TreeNode> stack = new Stack<TreeNode>();
		stack.push(root);
		while (!stack.isEmpty()) {
			final TreeNode node = stack.pop();
			final TreeNode left = node.left;
			node.left = node.right;
			node.right = left;
			if (node.left != null) {
				stack.push(node.left);
			}
			if (node.right != null) {
				stack.push(node.right);
			}
		}
		return root;
	}
}
