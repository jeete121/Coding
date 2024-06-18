**1. Maximum Depth of Binary Tree**

https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

public class Solution {

	public int maxDepth(TreeNode root) {

		if (root == null)
			return 0;
		return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));

	}
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode() {
	}

	TreeNode(int val) {
		this.val = val;
	}

	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}



**2. Balanced Binary Tree**

https://leetcode.com/problems/balanced-binary-tree/description/


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

Approach:: 1

public class Solution {

	int height(TreeNode root) {
		if (root == null)
			return 0;
		return 1 + Math.max(height(root.left), height(root.right));
	}

	public boolean isBalanced(TreeNode root) {

		if (root == null)
			return true;
		int leftHeight = height(root.left);
		int rightHeight = height(root.right);
		return Math.abs(leftHeight - rightHeight) <= 1 && isBalanced(root.left) && isBalanced(root.right);
	}
}


Approach:: 2

public class Solution {

	int height(TreeNode root) {
		if (root == null)
			return 0;
		int lH = height(root.left);
		if (lH == -1)
			return -1;
		int rH = height(root.right);
		if (rH == -1)
			return -1;
		if (Math.abs(lH - rH) > 1)
			return -1;
		return 1 + Math.max(height(root.left), height(root.right));
	}

	public boolean isBalanced(TreeNode root) {

		return height(root) == -1 ? false : true;
	}
}



**3. Diameter of Binary Tree**

https://leetcode.com/problems/diameter-of-binary-tree/description/



Approach:: 1

Find Left height, right height of every subtree.
Time Complexity:: O(N^2)
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

	int max = Integer.MIN_VALUE;

	public int height(TreeNode root) {
		if (root == null)
			return 0;
		return Math.max(height(root.left), height(root.right)) + 1;
	}

	public int diameterOfBinaryTree(TreeNode root) {

		if (root == null)
			return 0;
		int lh = height(root.left);
		int rh = height(root.right);
		max = Math.max(max, lh + rh);
		diameterOfBinaryTree(root.left);
		diameterOfBinaryTree(root.right);
		return max;

	}
}

Approach:: 2

Time Complexity:: O(N)

public class Solution {
	
	public int max = Integer.MIN_VALUE;

	public int height(TreeNode root) {
		if (root == null)
			return 0;
		int lh = height(root.left);
		int rh = height(root.right);
		max = Math.max(max, lh + rh);
		return 1 + Math.max(lh, rh);

	}

	public int diameterOfBinaryTree(TreeNode root) {

		height(root);
		return max;
	}
}


**4. Binary Tree Maximum Path Sum**

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
	
	int maxi = Integer.MIN_VALUE;

	public int maxSum(TreeNode root) {
		if (root == null) {
			return 0;
		}
		int lSum = Math.max(0, maxSum(root.left));
		int rSum = Math.max(0, maxSum(root.right));
		maxi = Math.max(maxi, lSum + rSum + root.val);
		return root.val + Math.max(lSum, rSum);
	}

	public int maxPathSum(TreeNode root) {
		maxSum(root);
		return maxi;
	}
}

**5. Check it two trees are Identical or Not (Same Tree)**

https://leetcode.com/problems/same-tree/description/


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
	
	public boolean isSameTree(TreeNode p, TreeNode q) {

		if (p == null && q == null)
			return true;
		if (p == null || q == null)
			return false;
		return (p.val == q.val ? true : false) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);

	}
}


**6. Binary Tree Zigzag Level Order Traversal**

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/


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
	
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

		List<List<Integer>> zigZag = new ArrayList<>();
		if (root == null) {
			return zigZag;
		}
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);
		int flag = 0;
		while (!q.isEmpty()) {
			int size = q.size();
			List<Integer> inner = new ArrayList<>();
			for (int i = 0; i < size; i++) {
				TreeNode node = q.poll();
				if (node.left != null)
					q.add(node.left);
				if (node.right != null)
					q.add(node.right);
				inner.add(node.val);
			}
			if (flag == 0) {
				zigZag.add(inner);
			} else {
				Collections.reverse(inner);
				zigZag.add(inner);
			}
			flag = 1 - flag;
		}

		return zigZag;
	}
}



**7. Boundary Traversal of binary tree**

https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

public class Solution {

	private void addLeftBoundary(Node node, ArrayList<Integer> ans) {
		Node curr = node.left;

		while (curr != null) {
			if (isLeaf(curr) == false) {
				ans.add(curr.data);
			}
			if (curr.left != null)
				curr = curr.left;
			else
				curr = curr.right;
		}
	}

	private void addRightBpundary(Node node, ArrayList<Integer> ans) {
		Node curr = node.right;
		ArrayList<Integer> rightTree = new ArrayList<>();
		while (curr != null) {
			if (isLeaf(curr) == false) {
				rightTree.add(curr.data);
			}
			if (curr.right != null)
				curr = curr.right;
			else
				curr = curr.left;
		}
		for (int i = rightTree.size() - 1; i >= 0; i--) {
			ans.add(rightTree.get(i));
		}
	}

	private void addLeaf(Node node, ArrayList<Integer> ans) {
		if (isLeaf(node) == true) {
			ans.add(node.data);
			return;
		}
		if (node.left != null)
			addLeaf(node.left, ans);
		if (node.right != null)
			addLeaf(node.right, ans);
	}

	private boolean isLeaf(Node node) {
		return node != null && node.left == null && node.right == null;
	}

	ArrayList<Integer> boundary(Node node) {

		ArrayList<Integer> ans = new ArrayList<>();
		if (node == null) {
			return ans;
		}
		if (isLeaf(node) == false)
			ans.add(node.data);
		addLeftBoundary(node, ans);
		addLeaf(node, ans);
		addRightBpundary(node, ans);

		return ans;
	}
}


**8. Vertical Order Traversal of a Binary Tree**

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/



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
	
	public List<List<Integer>> verticalTraversal(TreeNode root) {

		List<List<Integer>> verticalOrder = new ArrayList<>();

		if (root == null) {
			return verticalOrder;
		}
		TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> tMap = new TreeMap<>();
		Queue<Node> q = new LinkedList<Node>();
		q.add(new Node(root, 0, 0));

		while (!q.isEmpty()) {
			Node n = q.poll();
			TreeNode node = n.node;
			int x = n.vertical;
			int y = n.level;
			if (tMap.containsKey(x) == false) {
				tMap.put(x, new TreeMap<>());
			}
			if (tMap.get(x).containsKey(y) == false) {
				tMap.get(x).put(y, new PriorityQueue<>());
			}

			tMap.get(x).get(y).add(node.val);

			if (node.left != null) {
				q.add(new Node(node.left, x - 1, y + 1));
			}
			if (node.right != null) {
				q.add(new Node(node.right, x + 1, y + 1));
			}
		}

		for (TreeMap<Integer, PriorityQueue<Integer>> mq : tMap.values()) {
			verticalOrder.add(new ArrayList<>());
			for (PriorityQueue<Integer> nodes : mq.values()) {
				while (!nodes.isEmpty()) {
					verticalOrder.get(verticalOrder.size() - 1).add(nodes.poll());
				}
			}
		}

		return verticalOrder;
	}
}

class Node {
	TreeNode node;
	int vertical;
	int level;

	Node(TreeNode node, int vertical, int level) {
		this.node = node;
		this.vertical = vertical;
		this.level = level;
	}
}


**9. Top View of Binary Tree**

https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

public class Solution {

	static ArrayList<Integer> topView(Node root) {

		ArrayList<Integer> ans = new ArrayList<>();

		if (root == null) {
			return ans;
		}

		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(root, 0));
		Map<Integer, Integer> mp = new TreeMap<>();
		while (!q.isEmpty()) {
			Pair p = q.poll();

			Node node = p.node;
			int x = p.vLevel;

			if (mp.containsKey(x) == false) {
				mp.put(x, node.data);
			}
			if (node.left != null) {
				q.add(new Pair(node.left, x - 1));
			}
			if (node.right != null) {
				q.add(new Pair(node.right, x + 1));
			}

		}
		for (Integer m : mp.values()) {
			ans.add(m);
		}

		return ans;
	}
}

class Pair {

	Node node;
	int vLevel;

	Pair(Node node, int vLevel) {
		this.node = node;
		this.vLevel = vLevel;
	}
}

**10. Bottom View of Binary Tree**

https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


public class Solution {

	
	public ArrayList<Integer> bottomView(Node root) {
		ArrayList<Integer> ans = new ArrayList<>();

		if (root == null) {
			return ans;
		}
		Queue<Pair> q = new LinkedList<>();

		Map<Integer, Integer> mp = new TreeMap<>();

		q.add(new Pair(root, 0));

		while (!q.isEmpty()) {
			Pair p = q.poll();

			Node node = p.node;
			int x = p.vLevel;
			mp.put(x, node.data);
			if (node.left != null)
				q.add(new Pair(node.left, x - 1));
			if (node.right != null)
				q.add(new Pair(node.right, x + 1));
		}
		for (Integer i : mp.values()) {
			ans.add(i);
		}
		return ans;
	}
}

class Pair {

	Node node;
	int vLevel;

	Pair(Node node, int vLevel) {
		this.node = node;
		this.vLevel = vLevel;
	}
}

**11. Binary Tree Right Side View**

https://leetcode.com/problems/binary-tree-right-side-view/description/



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

Approach 1::

public class Solution {
	
	public List<Integer> rightSideView(TreeNode root) {

		List<Integer> ans = new ArrayList<>();
		if (root == null) {
			return ans;
		}
		List<List<Integer>> level = new ArrayList<>();

		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);

		while (!q.isEmpty()) {
			int size = q.size();
			List<Integer> inner = new ArrayList<>();
			for (int i = 0; i < size; i++) {
				TreeNode node = q.poll();
				if (node.left != null)
					q.add(node.left);
				if (node.right != null)
					q.add(node.right);
				inner.add(node.val);
			}
			level.add(inner);
		}
		for (int i = 0; i < level.size(); i++) {
			ans.add(level.get(i).get(level.get(i).size() - 1));
		}

		return ans;
	}
}


Approach 2::

public class Solution {
	
	private void rightSideView(TreeNode root, int level, List<Integer> ans) {
		if (root == null) {
			return;
		}

		if (ans.size() == level) {
			ans.add(root.val);
		}
		rightSideView(root.right, level + 1, ans);
		rightSideView(root.left, level + 1, ans);

	}

	public List<Integer> rightSideView(TreeNode root) {

		List<Integer> ans = new ArrayList<>();

		if (root == null) {
			return ans;
		}

		rightSideView(root, 0, ans);
		return ans;

	}
}

**12. Left View of Binary Tree**

https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

public class Tree {

	ArrayList<Integer> leftView(Node root) {
		ArrayList<Integer> ans = new ArrayList<>();
		if (root == null) {
			return ans;
		}

		List<List<Integer>> level = new ArrayList<>();

		Queue<Node> q = new LinkedList<>();

		q.add(root);

		while (!q.isEmpty()) {
			int size = q.size();

			List<Integer> inner = new ArrayList<>();
			for (int i = 0; i < size; i++) {
				Node node = q.poll();

				if (node.left != null)
					q.add(node.left);
				if (node.right != null)
					q.add(node.right);
				inner.add(node.data);
			}

			level.add(inner);
		}

		for (int i = 0; i < level.size(); i++) {
			ans.add(level.get(i).get(0));
		}
		return ans;
	}
}


**13. Check for Symmetrical Binary Trees**

https://leetcode.com/problems/symmetric-tree/description/


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
	
	private boolean isSymmetric(TreeNode left, TreeNode right) {
		if (left == null || right == null)
			return left == right;
		if (left.val != right.val)
			return false;
		return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
	}

	public boolean isSymmetric(TreeNode root) {
		return root == null || isSymmetric(root, root);
	}
}


**14. Binary Tree Paths**

https://leetcode.com/problems/binary-tree-paths/description/


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
	
	public void dfs(TreeNode root, List<String> ans, String path) {
		if (root == null) {
			return;
		}
		if (root.left == null && root.right == null) {
			path += root.val;
			ans.add(path);
			path = "";
			return;
		}
		path += root.val + "->";
		dfs(root.left, ans, path);
		dfs(root.right, ans, path);

	}

	public List<String> binaryTreePaths(TreeNode root) {
		List<String> ans = new ArrayList<>();
		dfs(root, ans, "");
		return ans;
	}
}


**15. Lowest Common Ancestor of a Binary Tree**

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/


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

		if (root == null || root == p || root == q) {
			return root;
		}

		TreeNode left = lowestCommonAncestor(root.left, p, q);
		TreeNode right = lowestCommonAncestor(root.right, p, q);
		if (left == null) {
			return right;
		} else if (right == null) {
			return left;
		} else {
			return root;
		}

	}
}

**16. Maximum Width of Binary Tree**

https://leetcode.com/problems/maximum-width-of-binary-tree/description/


Approach 1:: 

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
	
	public int widthOfBinaryTree(TreeNode root) {

		if (root == null) {
			return 0;
		}
		Queue<Node> q = new LinkedList<>();
		q.add(new Node(root, 0, 0));
		int ans = 1;
		while (!q.isEmpty()) {
			int size = q.size();
			int leftIndex = -1, rightIndex = -1;
			for (int i = 0; i < size; i++) {
				Node node = q.poll();

				if (i == 0) {
					leftIndex = node.index;
				} else if (i == size - 1 && i != 0) {
					rightIndex = node.index;
				}
				TreeNode n = node.node;

				if (n.left != null) {
					q.add(new Node(n.left, node.level + 1, 2 * node.index + 1));
				}
				if (n.right != null) {
					q.add(new Node(n.right, node.level + 1, 2 * node.index + 2));
				}

				if (leftIndex != -1 && rightIndex != -1) {
					ans = Math.max(rightIndex - leftIndex + 1, ans);
				}
			}
		}

		return ans;
	}
}

class Node {
	TreeNode node;
	int level;
	int index;

	Node(TreeNode node, int level, int index) {
		this.node = node;
		this.level = level;
		this.index = index;
	}
}


Approach 2:: How to avoid overflow


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
	
	public int widthOfBinaryTree(TreeNode root) {

		if (root == null) {
			return 0;
		}
		Queue<Node> q = new LinkedList<>();
		q.add(new Node(root, 0));
		int ans = 0;
		while (!q.isEmpty()) {
			int size = q.size();
			int leftIndex = 0, rightIndex = 0;
			int minx = q.peek().index;
			for (int i = 0; i < size; i++) {
				Node node = q.poll();
				int x = node.index - minx;
				if (i == 0) {
					leftIndex = node.index;
				}
				if (i == size - 1) {
					rightIndex = node.index;
				}
				TreeNode n = node.node;

				if (n.left != null) {
					q.add(new Node(n.left, 2 * x + 1));
				}
				if (n.right != null) {
					q.add(new Node(n.right, 2 * x + 2));
				}
			}
			ans = Math.max(rightIndex - leftIndex + 1, ans);
		}

		return ans;
	}
}

class Node {
	TreeNode node;
	int index;

	Node(TreeNode node, int index) {
		this.node = node;
		this.index = index;
	}
}

**17.1 Check for Children Sum Property in a Binary Tree**

https://www.geeksforgeeks.org/problems/children-sum-parent/1


public class Solution {

	private static boolean dfs(Node root) {
		if (root == null || root.left == null && root.right == null) {
			return true;
		}
		if (root.left != null && root.right == null) {
			if (root.left.data != root.data)
				return false;
			return dfs(root.left);
		} else if (root.left == null && root.right != null) {
			if (root.right.data != root.data) {
				return false;
			}
			return dfs(root.right);
		}
		return (root.left.data + root.right.data == root.data) && dfs(root.left) && dfs(root.right);
	}

	public static int isSumProperty(Node root) {

		if (root == null) {
			return 1;
		}

		return dfs(root) == true ? 1 : 0;
	}
}


**17.2 Children Sum Property in Binary Tree**

public class Solution {

	public static void changeTree(TreeNode root) {

		if (root == null)
			return;
		int child = 0;
		if (root.left != null)
			child += root.left.data;
		if (root.right != null)
			child += root.right.data;
		if (child >= root.data)
			root.data = child;
		else {
			if (root.left != null)
				root.left.data = root.data;

			if (root.right != null)
				root.right.data = root.data;
		}

		changeTree(root.left);
		changeTree(root.right);

		int tot = 0;
		if (root.left != null)
			tot += root.left.data;
		if (root.right != null)
			tot += root.right.data;
		if (root.left != null || root.right != null)
			root.data = tot;

	}
}


**18. All Nodes Distance K in Binary Tree**

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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
	
	private void markParent(TreeNode root, Map<TreeNode, TreeNode> parent) {
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);

		while (!q.isEmpty()) {
			TreeNode node = q.poll();
			if (node.left != null) {
				parent.put(node.left, node);
				q.add(node.left);
			}
			if (node.right != null) {
				parent.put(node.right, node);
				q.add(node.right);
			}
		}
	}

	public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
		Map<TreeNode, TreeNode> parent = new HashMap<>();
		markParent(root, parent);

		Map<TreeNode, Boolean> vis = new HashMap<>();
		Queue<TreeNode> q = new LinkedList<>();
		q.add(target);
		vis.put(target, true);
		int dis = 0;
		List<Integer> ans = new ArrayList<>();
		while (!q.isEmpty()) {

			int size = q.size();
			if (dis == k) {
				for (int i = 0; i < size; i++) {
					TreeNode n = q.poll();
					ans.add(n.val);
				}
			} else {
				for (int i = 0; i < size; i++) {
					TreeNode n = q.poll();
					if (!vis.containsKey(n.left) && n.left != null) {
						q.add(n.left);
						vis.put(n.left, true);
					}
					if (!vis.containsKey(n.right) && n.right != null) {
						q.add(n.right);
						vis.put(n.right, true);
					}
					if (parent.containsKey(n)) {
						TreeNode pn = parent.get(n);
						if (vis.containsKey(pn) == false) {
							q.add(pn);
							vis.put(pn, true);
						}
					}
				}
				dis++;
			}
		}

		return ans;
	}
}


**19. Minimum time taken to BURN the Binary Tree from a Node**

https://www.geeksforgeeks.org/problems/burning-tree/1

public class Solution {

	private static Node markParent(Node root, Map<Node, Node> parent, int target) {

		Queue<Node> q = new LinkedList<>();
		Node targetNode = null;
		q.add(root);

		while (!q.isEmpty()) {
			Node n = q.poll();

			if (n.data == target) {
				targetNode = n;
			}

			if (n.left != null) {
				q.add(n.left);
				parent.put(n.left, n);
			}

			if (n.right != null) {
				q.add(n.right);
				parent.put(n.right, n);
			}
		}

		return targetNode;
	}

	public static int minTime(Node root, int target) {

		Map<Node, Node> parent = new HashMap<>();
		Node targetNode = markParent(root, parent, target);
		Queue<Node> q = new LinkedList<>();
		Map<Node, Boolean> vis = new HashMap<>();

		q.add(targetNode);
		vis.put(targetNode, true);

		int time = 0;
		while (!q.isEmpty()) {

			int size = q.size();

			for (int i = 0; i < size; i++) {
				Node node = q.poll();

				if (node.left != null && vis.get(node.left) == null) {
					q.add(node.left);
					vis.put(node.left, true);
				}

				if (node.right != null && vis.get(node.right) == null) {
					q.add(node.right);
					vis.put(node.right, true);
				}

				if (parent.get(node) != null) {
					Node pn = parent.get(node);
					if (vis.get(pn) == null) {
						q.add(pn);
						vis.put(pn, true);
					}
				}
			}
			time++;
		}

		return time - 1;
	}
}


**20. Count Complete Tree Nodes**

https://leetcode.com/problems/count-complete-tree-nodes/description/

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
	
	private int leftHeight(TreeNode root) {
		int lh = 0;
		while (root.left != null) {
			root = root.left;
			lh++;
		}
		return lh;
	}

	private int rightHeight(TreeNode root) {
		int rh = 0;
		while (root.right != null) {
			root = root.right;
			rh++;
		}
		return rh;
	}

	public int countNodes(TreeNode root) {

		if (root == null) {
			return 0;
		}
		int lh = leftHeight(root);
		int rh = rightHeight(root);

		if (lh == rh) {
			return ((2 << (lh)) - 1);
		}
		return 1 + countNodes(root.left) + countNodes(root.right);

	}
}


**21. Construct Binary Tree from Preorder and Inorder Traversal**

Problem Link::

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/


Solution:: 

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
	
	private TreeNode buildTree(int[] preorder, int preL, int preR, int[] inorder, int inL, int inR,
			Map<Integer, Integer> mp) {
		if (preL > preR || inL > inR)
			return null;
		TreeNode root = new TreeNode(preorder[preL]);
		int inIndex = mp.get(preorder[preL]);
		int numsLeft = inIndex - inL;

		root.left = buildTree(preorder, preL + 1, preL + numsLeft, inorder, inL, inL + numsLeft, mp);

		root.right = buildTree(preorder, preL + numsLeft + 1, preR, inorder, inIndex + 1, inR, mp);

		return root;
	}

	public TreeNode buildTree(int[] preorder, int[] inorder) {

		Map<Integer, Integer> mp = new HashMap<>();

		for (int i = 0; i < inorder.length; i++) {
			mp.put(inorder[i], i);
		}

		return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, mp);
	}
}



**22. Construct Binary Tree from Inorder and Postorder Traversal**

Problem Link:: 

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/


Solution::


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
	
	private TreeNode buildTree(int[] inorder, int inL, int inR, int[] postorder, int postL, int postR,
			Map<Integer, Integer> mp) {

		if (inL > inR || postL > postR)
			return null;
		TreeNode root = new TreeNode(postorder[postR]);

		int inIndex = mp.get(postorder[postR]);
		int leftNum = inIndex - inL;
		int rightNum = inR - inIndex;

		root.left = buildTree(inorder, inL, inIndex - 1, postorder, postL, postR - rightNum - 1, mp);

		root.right = buildTree(inorder, inIndex + 1, inR, postorder, postR - rightNum, postR - 1, mp);

		return root;
	}

	public TreeNode buildTree(int[] inorder, int[] postorder) {

		Map<Integer, Integer> mp = new HashMap<>();

		for (int i = 0; i < inorder.length; i++) {
			mp.put(inorder[i], i);
		}

		return buildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1, mp);

	}
}

**23. Serialize and Deserialize Binary Tree**

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

public public class Codec {

	public String serialize(TreeNode root) {
		if (root == null) {
			return "";
		}
		Queue<TreeNode> q = new LinkedList<>();
		StringBuilder res = new StringBuilder();

		q.add(root);

		while (!q.isEmpty()) {
			TreeNode node = q.poll();
			if (node == null) {
				res.append("# ");
				continue;
			}
			res.append(node.val + " ");
			q.add(node.left);
			q.add(node.right);
		}
		return res.toString();

	}

	public TreeNode deserialize(String data) {

		if (data == "") {
			return null;
		}
		Queue<TreeNode> q = new LinkedList<>();
		String[] values = data.split(" ");

		TreeNode root = new TreeNode(Integer.parseInt(values[0]));
		q.add(root);

		for (int i = 1; i < values.length; i++) {
			TreeNode node = q.poll();
			if (!values[i].equals("#")) {
				TreeNode left = new TreeNode(Integer.parseInt(values[i]));
				node.left = left;
				q.add(left);
			}
			if (!values[++i].equals("#")) {
				TreeNode right = new TreeNode(Integer.parseInt(values[i]));
				node.right = right;
				q.add(right);
			}
		}
		return root;

	}
}

**24. Morris Traversal (Inorder)**

https://leetcode.com/problems/binary-tree-inorder-traversal/description/

public class Solution {
	
	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> inorder = new ArrayList<>();
		TreeNode cur = root;
		while (cur != null) {
			if (cur.left == null) {
				inorder.add(cur.val);
				cur = cur.right;
			} else {
				TreeNode prev = cur.left;
				while (prev.right != null && prev.right != cur) {
					prev = prev.right;
				}
				if (prev.right == null) {
					prev.right = cur;
					cur = cur.left;
				} else {
					prev.right = null;
					inorder.add(cur.val);
					cur = cur.right;
				}
			}
		}
		return inorder;

	}
}

**25. Morris Traversal (Preorder)**

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

public class Solution {
	
	public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> preorder = new ArrayList<>();
		TreeNode cur = root;
		while (cur != null) {
			if (cur.left == null) {
				preorder.add(cur.val);
				cur = cur.right;
			} else {
				TreeNode prev = cur.left;
				while (prev.right != null && prev.right != cur) {
					prev = prev.right;
				}
				if (prev.right == null) {
					prev.right = cur;
					preorder.add(cur.val);
					cur = cur.left;
				} else {
					prev.right = null;
					cur = cur.right;
				}
			}
		}
		return preorder;

	}
}

**26. Flatten Binary Tree to Linked List**

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


Aproach 1::

public class Solution {
	
	TreeNode prev = null;

	public void flatten(TreeNode root) {
		if (root == null) {
			return;
		}
		flatten(root.right);
		flatten(root.left);
		root.right = prev;
		root.left = null;
		prev = root;
	}
}

Approach 2:

public class Solution {
	
	public void flatten(TreeNode root) {

		if (root == null) {
			return;
		}
		Stack<TreeNode> st = new Stack<>();
		st.push(root);

		TreeNode cur = root;
		while (!st.isEmpty()) {
			cur = st.pop();
			if (cur.right != null) {
				st.push(cur.right);
			}
			if (cur.left != null) {
				st.push(cur.left);
			}
			if (!st.isEmpty())
				cur.right = st.peek();
			cur.left = null;
		}

	}
}


Approach 3:

public class Solution {
	
	public void flatten(TreeNode root) {

		if (root == null) {
			return;
		}
		TreeNode cur = root;

		while (cur != null) {
			if (cur.left != null) {
				TreeNode prev = cur.left;
				while (prev.right != null)
					prev = prev.right;
				prev.right = cur.right;
				cur.right = cur.left;
				cur.left = null;
			}
			cur = cur.right;
		}

	}
}