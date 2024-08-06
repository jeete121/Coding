**1. Maximum Depth of Binary Tree**

https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


```css
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2
```

Solution

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

	public int maxDepth(TreeNode root) {

		if (root == null)
			return 0;
		return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));

	}
}
```



**2. Balanced Binary Tree**

https://leetcode.com/problems/balanced-binary-tree/description/

Given a binary tree, determine if it is height-balanced

```css
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true
```


Approach:: 1

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
```


Approach:: 2

```java
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
```



**3. Diameter of Binary Tree**

https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

```css
Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1
```

Approach:: 1

Find Left height, right height of every subtree.
Time Complexity:: O(N^2)

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
```
Approach:: 2

Time Complexity:: O(N)

```java
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
```

**4. Binary Tree Maximum Path Sum**

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

```css
Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```



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
```

**5. Check it two trees are Identical or Not (Same Tree)**

https://leetcode.com/problems/same-tree/description/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

```css
Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
```


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
	
	public boolean isSameTree(TreeNode p, TreeNode q) {

		if (p == null && q == null)
			return true;
		if (p == null || q == null)
			return false;
		return (p.val == q.val ? true : false) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);

	}
}
```


**6. Binary Tree Zigzag Level Order Traversal**

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

```css
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
```


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
```



**7. Boundary Traversal of binary tree**

https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

```css
Example 1:
Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:
Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
```

```java
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
```


**8. Vertical Order Traversal of a Binary Tree**

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

```css
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
```


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
```


**9. Top View of Binary Tree**

https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

```css
       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
```

Solution


```java
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
```

**10. Bottom View of Binary Tree**

https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.


```css
                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :
Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
```

Solution

```java
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
```

**11. Binary Tree Right Side View**

https://leetcode.com/problems/binary-tree-right-side-view/description/

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


```css
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
```


Approach 1::

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
```


Approach 2::

```java
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
```

**12. Left View of Binary Tree**

https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

```css
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3
```

Solution


```java
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
```


**13. Check for Symmetrical Binary Trees**

https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


```css
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
```


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
```


**14. Binary Tree Paths**

https://leetcode.com/problems/binary-tree-paths/description/

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

```css
Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
```

Solution

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
```


**15. Lowest Common Ancestor of a Binary Tree**

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


```css
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1
```


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
```

**16. Maximum Width of Binary Tree**

https://leetcode.com/problems/maximum-width-of-binary-tree/description/

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

```css
Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
```


Approach 1:: 

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
```


Approach 2:: How to avoid overflow


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
```

**17.1 Check for Children Sum Property in a Binary Tree**

https://www.geeksforgeeks.org/problems/children-sum-parent/1

Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

```css
Example 1:
Input:
Binary tree
       35
      /   \
     20  15
    /  \  /  \
   15 5 10 5
Output: 
1
Explanation: 
Here, every node is sum of its left and right child.

Example 2:
Input:
Binary tree
       1
     /   \
    4    3
   /  
  5    
Output: 
0
Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
```


```java
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
```


**17.2 Children Sum Property in Binary Tree**

```java
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
```


**18. All Nodes Distance K in Binary Tree**

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


```css
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
```

Solution


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
```


**19. Minimum time taken to BURN the Binary Tree from a Node**

https://www.geeksforgeeks.org/problems/burning-tree/1

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

```css
Examples : 
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
```

Solution

```java
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
```

**20. Count Complete Tree Nodes**

https://leetcode.com/problems/count-complete-tree-nodes/description/

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.


```css
Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1
```

Solution


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
```

**21. Construct Binary Tree from Preorder and Inorder Traversal**

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.


```css
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```


Solution:: 

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
```



**22. Construct Binary Tree from Inorder and Postorder Traversal**

Problem Link:: 

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.


```css
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

Solution::


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
```


**23. Serialize and Deserialize Binary Tree**

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

```css
Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
```

Solution

```java
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
```

**24. Morris Traversal (Inorder)**

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

Solution

```java
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
```

**25. Morris Traversal (Preorder)**

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

Solution

```java
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
```

**26. Flatten Binary Tree to Linked List**

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


```css
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]
```

Aproach 1::

```java
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
```

Approach 2:

```java
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
```


Approach 3:

```java
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
```