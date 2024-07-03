**1. Search in a Binary Search Tree**

https://leetcode.com/problems/search-in-a-binary-search-tree/description/

You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


```java
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
```

**2. Ceil in BST**

https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Approach 1: Recursive

```java
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
```

Approach 2: Iterative

```java
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
```

**3. Floor in BST**

https://www.geeksforgeeks.org/problems/floor-in-bst/1

You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.

Note: when x is smaller than the smallest node of BST then returns -1.

```java
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
```



**4. Insert into a Binary Search Tree**


https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

```java
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
```

**5. Delete Node in a BST**

https://leetcode.com/problems/delete-node-in-a-bst/description/

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

```java
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
```

**6. Kth Smallest Element in a BST**

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
public class Solution {
	
	int ans = 0;
	int cnt = 0;

	private void inorder(TreeNode root, int k) {
		if (root == null || cnt >= k) {
			return;
		}
		inorder(root.left, k);
		cnt++;
		if (cnt == k) {
			ans = root.val;
			return;
		}
		inorder(root.right, k);

	}

	public int kthSmallest(TreeNode root, int k) {
		inorder(root, k);
		return ans;

	}
}
```


**7. Validate Binary Search Tree**

https://leetcode.com/problems/validate-binary-search-tree/description/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left  subtree of a node contains only nodes with keys less than the node's key.

The right subtree of a node contains only nodes with keys greater than the node's key.

Both the left and right subtrees must also be binary search trees.


```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {

	private boolean isValidBST(TreeNode root, long min, long max) {
		if (root == null) {
			return true;
		}
		if (root.val <= min || root.val >= max) {
			return false;
		}
		return isValidBST(root.left, min, root.val) && isValidBST(root.right, root.val, max);

	}

	public boolean isValidBST(TreeNode root) {

		return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
	}
}
```


**8. Lowest Common Ancestor of a Binary Search Tree**

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia:

The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).


```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 
public class Solution {
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		if (root == null) {
			return null;
		}
		if (root.val < p.val && root.val < q.val) {
			return lowestCommonAncestor(root.right, p, q);
		}
		if (root.val > p.val && root.val > q.val) {
			return lowestCommonAncestor(root.left, p, q);
		}
		return root;
	}
}
```

**9. Construct Binary Search Tree from Preorder Traversal**

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
public class Solution {
	int pos = 0;

	private TreeNode bstFromPreorder(int[] preorder, int max) {
		if (pos == preorder.length || preorder[pos] > max) {
			return null;
		}
		TreeNode root = new TreeNode(preorder[pos++]);
		root.left = bstFromPreorder(preorder, root.val);
		root.right = bstFromPreorder(preorder, max);
		return root;
	}

	public TreeNode bstFromPreorder(int[] preorder) {

		return bstFromPreorder(preorder, Integer.MAX_VALUE);

	}
}
```

**10. Inorder Successor in BST**

https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.


Example 1:

```css
Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3 
Explanation: 
Inorder traversal : 1 2 3 
Hence, inorder successor of 2 is 3.
```

Solution::

```java
class Node {
	int data;
	Node left, right;

	Node(int d) {
		data = d;
		left = right = null;
	}
}

public class Solution {

	public Node inorderSuccessor(Node root, Node x) {
		Node successor = null;
		while (root != null) {
			if (x.data >= root.data) {
				root = root.right;
			} else {
				successor = root;
				root = root.left;
			}
		}

		return successor;
	}
}
```


**11. Predecessor and Successor**

https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 


Example 1:

```css
Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
key = 8 
Output: 4 9
Explanation: 
In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
```

Solution

```java
class Node {
	int data;
	Node left, right;

	Node(int d) {
		data = d;
		left = right = null;
	}
}

public class Solution {
	private static Node findSuccessor(Node root, int x) {

		Node successor = null;
		while (root != null) {
			if (x >= root.data) {
				root = root.right;
			} else {
				successor = root;
				root = root.left;
			}
		}
		return successor;
	}

	private static Node findPrecessor(Node root, int x) {

		Node predecessor = null;
		while (root != null) {
			if (x > root.data) {
				predecessor = root;
				root = root.right;
			} else {
				root = root.left;
			}
		}
		return predecessor;
	}

	public static void findPreSuc(Node root, Node[] pre, Node[] suc, int key) {

		suc[0] = findSuccessor(root, key);
		pre[0] = findPrecessor(root, key);
	}
}
```

**12. Binary Search Tree Iterator**

https://leetcode.com/problems/binary-search-tree-iterator/description/

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.

boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.

int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 
public class BSTIterator {

	private Stack<TreeNode> st = new Stack<>();

	public BSTIterator(TreeNode root) {
		pushAll(root);
	}

	public int next() {
		TreeNode node = st.pop();
		pushAll(node.right);
		return node.val;
	}

	public boolean hasNext() {
		return !st.isEmpty();
	}

	private void pushAll(TreeNode root) {
		if (root == null) {
			return;
		}

		while (root != null) {
			st.push(root);
			root = root.left;
		}
	}
}
```


**13. Two Sum IV - Input is a BST**

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
	public boolean findTarget(TreeNode root, int k) {

		BSTIterator l = new BSTIterator(root, false);
		BSTIterator r = new BSTIterator(root, true);
		int i = l.next();
		int j = r.next();

		while (i < j) {
			if (i + j == k) {
				return true;
			}
			if (i + j > k) {
				j = r.next();
			} else {
				i = l.next();
			}

		}
		return false;
	}
}

class BSTIterator {

	private Stack<TreeNode> st = new Stack<>();
	boolean reverse = true;

	BSTIterator(TreeNode root, boolean isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	public boolean hasNext() {
		return !st.isEmpty();
	}

	public int next() {
		TreeNode node = st.pop();
		if (reverse == false) {
			pushAll(node.right);
		} else {
			pushAll(node.left);
		}
		return node.val;
	}

	private void pushAll(TreeNode root) {
		if (root == null) {
			return;
		}
		while (root != null) {
			st.push(root);
			if (reverse == false) {
				root = root.left;
			} else {
				root = root.right;
			}
		}
	}
}
```