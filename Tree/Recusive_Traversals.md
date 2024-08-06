**1. Inorder Traversal**

https://leetcode.com/problems/binary-tree-inorder-traversal/description/

Given the root of a binary tree, return the inorder traversal of its nodes' values.


```css
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
```


Left, Root, Right

```java
public class Solution {
	
	public void inorderTraversal(TreeNode root, List<Integer> res) {
		if (root == null)
			return;
		inorderTraversal(root.left, res);
		res.add(root.val);
		inorderTraversal(root.right, res);
	}

	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<Integer>();
		if (root == null)
			return res;
		inorderTraversal(root, res);
		return res;

	}
}
```


**2. Preorder Traversal**

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Given the root of a binary tree, return the preorder traversal of its nodes' values.


```css
Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
```

Root, Left, Right

```java
public class Solution {
	
	public void preorderTraversal(TreeNode root, List<Integer> res) {
		if (root == null)
			return;
		res.add(root.val);
		preorderTraversal(root.left, res);
		preorderTraversal(root.right, res);
	}

	public List<Integer> preorderTraversal(TreeNode root) {

		List<Integer> res = new ArrayList<>();
		preorderTraversal(root, res);
		return res;
	}
}
```


**3. Postorder Traversal**

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

Given the root of a binary tree, return the postorder traversal of its nodes' values.

```css
Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
```


Left,Right,Root

```java
public class Solution {
	
	public void postorderTraversal(TreeNode root, List<Integer> res) {
		if (root == null)
			return;
		postorderTraversal(root.left, res);
		postorderTraversal(root.right, res);
		res.add(root.val);
	}

	public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		postorderTraversal(root, res);
		return res;
	}
}
```
