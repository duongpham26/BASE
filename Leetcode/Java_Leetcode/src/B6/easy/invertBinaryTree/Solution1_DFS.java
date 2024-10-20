package B6.easy.invertBinaryTree;

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution1_DFS {
	public TreeNode invertTree(TreeNode root) {
		if (root == null) {
			return null;
		}
		invertTree(root.left);
		TreeNode temp = root.right;
		root.right = root.left;
		root.left = temp;
		invertTree(root.left);
		return root;
	}
}

//class Solution {
//    public TreeNode invertTree(TreeNode root) {
//        if(root == null) {
//            return null;
//        }
//        final TreeNode left = root.left, right = root.right;
//        root.left = invertTree(right);
//        root.right = invertTree(left);
//        return root;
//    }
//}
