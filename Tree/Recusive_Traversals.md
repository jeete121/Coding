**1. Inorder Traversal**

https://leetcode.com/problems/binary-tree-inorder-traversal/description/

Left, Root, Right

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


**2. Preorder Traversal**

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Root, Left, Right

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


**3. Postorder Traversal**

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

Left,Right,Root

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
