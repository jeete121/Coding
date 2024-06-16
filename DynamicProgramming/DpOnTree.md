General Format

int solve(Node root, int res) {
    
		if (root == null)
			return 0;
		int l = solve(root.left, res);
		int r = solve(root.right, res);
		int tempAns = calculate temp ans (1+Math.max(l,r));
		int ans = Math.max(tempAns, relation);
		res = Math.max(res, ans);
		return tempAns;
}

1. Diameter of Binary Tree (https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)

public class Solution {
	
	int res;
	int solve(Node root) {
		if (root == null)
			return 0;
		int l = solve(root.left);
		int r = solve(root.right);
		int temp = Math.max(l, r) + 1;
		int ans = Math.max(temp, l + r + 1);
		res = Math.max(res, ans);
		return temp;
	}

	int diameter(Node root) {

		// Your code here
		res = 0;
		solve(root);
		return res;
	}
}

2. Maximum path sum from any node to any/Binary Tree Maximum Path Sum
 (https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)


public class Solution {
	
	int res;
	public int solve(TreeNode root) {
		if (root == null)
			return 0;
		int l = solve(root.left);
		int r = solve(root.right);
		int temp = Math.max(Math.max(r, l) + root.val, root.val);
		int ans = Math.max(temp, l + r + root.val);
		res = Math.max(res, ans);
		return temp;
	}

	public int maxPathSum(TreeNode root) {

		res = Integer.MIN_VALUE;
		solve(root);
		return res;
	}
}