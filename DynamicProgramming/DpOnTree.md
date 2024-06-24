# General Format

```java
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

```


**1. Diameter of Binary Tree**

https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).


```java
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
		res = 0;
		solve(root);
		return res;
	}
}
```

**2. Maximum path sum from any node to any/Binary Tree Maximum Path Sum**

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.


```java
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
```