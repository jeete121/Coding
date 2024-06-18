**1. Inorder Traversal**

https://leetcode.com/problems/binary-tree-inorder-traversal/description/

```java
public class Solution {

	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<Integer>();
		Stack<TreeNode> st = new Stack<>();
		TreeNode node = root;
		if (root == null)
			return res;
		while (true) {
			if (node != null) {
				st.push(node);
				node = node.left;
			} else {
				if (st.isEmpty())
					break;
				node = st.pop();
				res.add(node.val);
				node = node.right;
			}
		}
		return res;
	}
}
```


**2. Preorder Traversal**

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

```java
public class Solution {
	
	public List<Integer> preorderTraversal(TreeNode root) {

		List<Integer> res = new ArrayList<>();
		Stack<TreeNode> st = new Stack<>();
		if (root == null)
			return res;
		st.push(root);
		while (!st.empty()) {
			TreeNode node = st.peek();
			st.pop();
			res.add(node.val);
			if (node.right != null)
				st.push(node.right);
			if (node.left != null)
				st.push(node.left);

		}
		return res;

	}
}
```


**3. Postorder Traversal**

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

Approach 1: Using 2 Stacks

```java
public class Solution {
	
	public List<Integer> postorderTraversal(TreeNode root) {
		Stack<TreeNode> st1 = new Stack<>();
		Stack<Integer> st2 = new Stack<>();
		List<Integer> res = new ArrayList<>();
		if (root == null)
			return res;
		st1.push(root);
		while (!st1.empty()) {
			TreeNode node = st1.pop();
			st2.push(node.val);
			if (node.left != null)
				st1.push(node.left);
			if (node.right != null)
				st1.push(node.right);
		}
		while (!st2.empty()) {
			res.add(st2.pop());
		}
		return res;
	}
}
```

Approach 2:: Using 1 Stack

```java
public class Solution {
	
	public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		if (root == null)
			return res;
		Stack<TreeNode> st = new Stack<>();
		TreeNode cur = root;
		while (cur != null || !st.empty()) {
			if (cur != null) {
				st.push(cur);
				cur = cur.left;
			} else {
				TreeNode temp = st.peek().right;
				if (temp == null) {
					temp = st.pop();
					res.add(temp.val);
					while (!st.empty() && temp == st.peek().right) {
						temp = st.pop();
						res.add(temp.val);
					}
				} else
					cur = temp;
			}
		}

		return res;
	}
}
```


**4. Level Order Traversal**

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

```java
public class Solution {
	
	public List<List<Integer>> levelOrder(TreeNode root) {

		List<List<Integer>> res = new ArrayList<>();
		Queue<TreeNode> q = new LinkedList<>();
		if (root == null)
			return res;
		q.add(root);
		while (!q.isEmpty()) {

			List<Integer> level = new ArrayList<>();
			int size = q.size();
			for (int i = 0; i < size; i++) {
				TreeNode node = q.poll();
				level.add(node.val);
				if (node.left != null)
					q.add(node.left);
				if (node.right != null)
					q.add(node.right);
			}
			res.add(level);
		}
		return res;

	}
}
```


**Preorder Inorder Postorder in One Iteration**

```java
public class Solution {

	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> preorder = new ArrayList<Integer>();
		List<Integer> inorder = new ArrayList<Integer>();
		List<Integer> postorder = new ArrayList<Integer>();
		Stack<Pair> st = new Stack<>();
		if (root == null)
			return inorder;
		st.push(new Pair(root, 1));
		while (!st.empty()) {
			Pair p = st.peek();
			if (p.num == 1) {
				preorder.add(p.node.val);
				st.peek().num++;
				if (p.node.left != null)
					st.push(new Pair(p.node.left, 1));

			} else if (p.num == 2) {
				inorder.add(p.node.val);
				st.peek().num++;
				if (p.node.right != null)
					st.push(new Pair(p.node.right, 1));

			} else {
				postorder.add(p.node.val);
				st.pop();
			}
		}

		return inorder;

	}
}

class Pair {
	public TreeNode node;
	public int num;

	public Pair(TreeNode node, int num) {
		this.node = node;
		this.num = num;
	}
}
```