1. Search in a Binary Search Tree: https://leetcode.com/problems/search-in-a-binary-search-tree/description/

You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


public class Solution {
	
	public TreeNode searchBST(TreeNode root, int val) {

		if (root == null || root.val == val) {
			return root;
		}
		if (root.val < val)
			return searchBST(root.right, val);
		return searchBST(root.left, val);
	}
}

2. Ceil in BST : https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Approach 1: Recursive

public class Tree {

	int ceil = -1;

	private void findCeilHelper(Node root, int key) {
		if (root == null) {
			return;
		}
		if (root.data >= key) {
			ceil = root.data;
			findCeil(root.left, key);
		} else {
			findCeil(root.right, key);
		}
	}

	int findCeil(Node root, int key) {

		findCeilHelper(root, key);
		return ceil;

	}
}


Approach 2: Iterative

public class Tree {

	int findCeil(Node root, int key) {

		int ceil = -1;

		while (root != null) {

			if (root.data == key) {
				return root.data;
			}
			if (root.data > key) {
				ceil = root.data;
				root = root.left;
			} else {
				root = root.right;
			}
		}
		return ceil;
	}
}

3. Floor in BST: https://www.geeksforgeeks.org/problems/floor-in-bst/1

You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.

Note: when x is smaller than the smallest node of BST then returns -1.

public class Solution {

	public static int floor(Node root, int x) {

		int floor = -1;
		while (root != null) {
			if (root.data == x) {
				return root.data;
			}
			if (root.data < x) {
				floor = root.data;
				root = root.right;
			} else {
				root = root.left;
			}
		}

		return floor;
	}
}



4. Insert into a Binary Search Tree: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

public class Solution {
	
	public TreeNode insertIntoBST(TreeNode root, int val) {

		if (root == null) {
			root = new TreeNode(val);
			return root;
		}
		TreeNode node = root;
		while (node != null) {
			if (node.val < val) {
				if (node.right != null)
					node = node.right;
				else {
					node.right = new TreeNode(val);
					break;
				}
			} else {
				if (node.left != null)
					node = node.left;
				else {
					node.left = new TreeNode(val);
					break;
				}
			}
		}

		return root;

	}
}


5. Delete Node in a BST: https://leetcode.com/problems/delete-node-in-a-bst/description/

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

public class Solution {
	
	public TreeNode deleteNode(TreeNode root, int key) {

		if (root == null) {
			return null;
		}
		if (root.val == key) {
			return helper(root);
		}
		TreeNode node = root;

		while (root != null) {
			if (root.val > key) {
				if (root.left != null && root.left.val == key) {
					root.left = helper(root.left);
					break;
				} else {
					root = root.left;
				}
			} else {
				if (root.right != null && root.right.val == key) {
					root.right = helper(root.right);
					break;
				} else {
					root = root.right;
				}
			}
		}

		return node;
	}

	private TreeNode helper(TreeNode root) {
		if (root.left == null) {
			return root.right;
		} else if (root.right == null) {
			return root.left;
		}
		TreeNode rightChild = root.right;
		TreeNode lastRight = findLastRight(root.left);
		lastRight.right = rightChild;
		return root.left;
	}

	private TreeNode findLastRight(TreeNode root) {
		if (root.right == null) {
			return root;
		}
		return findLastRight(root.right);
	}
}