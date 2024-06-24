**1. Introduction to Graph**

https://takeuforward.org/graph/introduction-to-graph/

**2. Graph Representation**

https://takeuforward.org/graph/graph-representation-in-c/

**3. Connected Components in Graphs**

https://takeuforward.org/graph/connected-components-in-graphs/

**4. Breadth First Search (BFS): Level Order Traversal**

https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/

Problem Link:: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Solution:: 

```java
public class Solution {

    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        int vis[]= new int[V+1];
        for(int i=0;i<=V;i++)
        {
            vis[i]=0;
        }
        Queue<Integer> q = new LinkedList<>();
        
        q.add(0);
        vis[0]=1;
        ArrayList<Integer> res = new ArrayList<>();
        while(!q.isEmpty())
        {
          Integer val= q.poll();
          res.add(val);
          List<Integer> list = adj.get(val);
          for(int i=0;i<list.size();i++)
          {
              if(vis[list.get(i)]==0)
                {
                    q.add(list.get(i));
                    vis[list.get(i)]=1;
                }
          }
        }
        return res;
    }
}
```

**6. Depth First Search (DFS)**

https://takeuforward.org/data-structure/depth-first-search-dfs/

Problem Link:: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

You are given a connected undirected graph. Perform a Depth First Traversal of the graph.

Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

Solution:: 

```java
public class Solution {

	ArrayList<Integer> dfsArray;

	void dfs(int node, ArrayList<ArrayList<Integer>> adj, int vis[]) {

		dfsArray.add(node);
		vis[node] = 1;
		ArrayList<Integer> list = adj.get(node);
		for (int i = 0; i < list.size(); i++) {
			if (vis[list.get(i)] == 0) {
				dfs(list.get(i), adj, vis);
			}
		}
	}

	// Function to return a list containing the DFS traversal of the graph.
	public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
		// Code here

		int vis[] = new int[V + 1];
		for (int i = 0; i <= V; i++)
			vis[i] = 0;
		dfsArray = new ArrayList<>();
		dfs(0, adj, vis);

		return dfsArray;
	}
}
```

**7. Number of Provinces**

https://takeuforward.org/data-structure/number-of-provinces/

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-provinces/1

Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Solution::

```java
public class Solution {

	static void dfs(int start, ArrayList<ArrayList<Integer>> adj, int vis[]) {
		vis[start] = 1;

		for (Integer it : adj.get(start)) {
			if (vis[it] == 0) {
				dfs(it, adj, vis);
			}
		}
	}

	static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {

		int vis[] = new int[V];
		ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
		for (int i = 0; i < V; i++) {
			adjList.add(new ArrayList<>());
		}
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {

				if (adj.get(i).get(j) == 1 && i != j) {
					adjList.get(i).add(j);
					adjList.get(j).add(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				cnt++;
				dfs(i, adjList, vis);
			}
		}

		return cnt;
	}
}
```

**8. Number of Islands | Number of Connected Components in Matrix**

Problem Link:: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output: 1

Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

Solution::

```java
public class Solution {

	int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
	int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

	private void dfs(int x, int y, char[][] grid, int vis[][]) {
		vis[x][y] = 1;
		int n = grid.length;
		int m = grid[0].length;
		for (int i = 0; i < 8; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && vis[newX][newY] == 0) {
				dfs(newX, newY, grid, vis);
			}
		}
	}

	// Function to find the number of islands.
	public int numIslands(char[][] grid) {

		int cnt = 0;
		int n = grid.length;
		int m = grid[0].length;
		int vis[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == 0 && grid[i][j] == '1') {
					cnt++;
					dfs(i, j, grid, vis);
				}
			}
		}

		return cnt;

	}
}
```


**9. Flood Fill Algorithm - Graphs**

https://takeuforward.org/graph/flood-fill-algorithm-graphs/

Problem Link:: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.


Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}

Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Solution::

```java
public class Solution {

	int dx[] = { 0, 1, -1, 0 };
	int dy[] = { 1, 0, 0, -1 };

	public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
		// Code here
		int n = image.length;
		int m = image[0].length;
		Queue<Pair> qp = new LinkedList<>();
		int vis[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
			}
		}
		vis[sr][sc] = 1;
		int color = image[sr][sc];
		image[sr][sc] = newColor;
		qp.add(new Pair(sr, sc));

		while (!qp.isEmpty()) {
			Pair p = qp.poll();
			int x = p.x;
			int y = p.y;
			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == 0
						&& image[newX][newY] == color) {
					vis[newX][newY] = 1;
					image[newX][newY] = newColor;
					qp.add(new Pair(newX, newY));
				}
			}
		}

		return image;
	}

}

class Pair {

	int x;
	int y;

	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
```



**10. Rotten Oranges**

https://takeuforward.org/data-structure/rotten-oranges/

Problem Link:: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 


Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1

Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.

Solution::

```java
public class Solution {

	int cntFresh;

	public boolean isValid(int i, int j, int n, int m) {
		if (i >= 0 && i < n && j >= 0 && j < m)
			return true;
		return false;
	}

	public int bfs(int[][] grid, int[][] vis, Queue<Pair> qp) {
		int cnt = 0;
		int n = grid.length;
		int m = grid[0].length;
		int dx[] = { -1, 0, 1, 0 };
		int dy[] = { 0, 1, 0, -1 };
		while (!qp.isEmpty()) {

			Pair p = qp.poll();
			int x = p.getKey();
			int y = p.getValue();
			int t = p.getTime();
			cnt = Math.max(t, cnt);
			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (isValid(newX, newY, n, m) && grid[newX][newY] == 1 && vis[newX][newY] == 0) {
					vis[newX][newY] = 1;
					qp.add(new Pair(newX, newY, t + 1));
					cntFresh--;
				}
			}

		}

		return cntFresh == 0 ? cnt : -1;
	}

	// Function to find the minimum time required to rot all oranges.
	public int orangesRotting(int[][] grid) {
		// Code here
		int n = grid.length;
		int m = grid[0].length;
		int vis[][] = new int[n][m];
		Queue<Pair> qp = new LinkedList<>();
		cntFresh = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
				if (grid[i][j] == 2) {
					qp.add(new Pair(i, j, 0));
					vis[i][j] = 1;
				}
				if (grid[i][j] == 1)
					cntFresh++;
			}
		}

		return bfs(grid, vis, qp);
	}
}

class Pair {

	private Integer key;
	private Integer value;
	private Integer time;

	public Integer getKey() {
		return this.key;
	}

	public Integer getValue() {
		return this.value;
	}

	public Integer getTime() {
		return this.time;
	}

	Pair(Integer key, Integer value, Integer time) {
		this.key = key;
		this.value = value;
		this.time = time;
	}
}
```



**11. Detect Cycle in an Undirected Graph (using BFS)**

https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Solution::

```java
public class Solution {

	public boolean bfs(int src, ArrayList<ArrayList<Integer>> adj, boolean vis[]) {

		Queue<Pair> qp = new LinkedList<>();
		vis[src] = true;
		qp.add(new Pair(src, -1));

		while (!qp.isEmpty()) {

			int node = qp.peek().node;
			int parent = qp.peek().parent;

			qp.remove();

			for (Integer it : adj.get(node)) {
				if (vis[it] == false) {
					vis[it] = true;
					qp.add(new Pair(it, node));
				} else if (parent != it)
					return true;
			}
		}
		return false;
	}

	// Function to detect cycle in an undirected graph.
	public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
		// Code here

		boolean vis[] = new boolean[V];
		Arrays.fill(vis, false);
		for (int i = 0; i < V; i++)
			if (vis[i] == false)
				if (bfs(i, adj, vis))
					return true;

		return false;

	}
}

class Pair {

	int node;
	int parent;

	Pair(int node, int parent) {
		this.node = node;
		this.parent = parent;
	}

}
```


**12. Detect Cycle in an Undirected Graph (using DFS)**

https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Solution::

```java
public class Solution {

	public boolean dfs(int node, ArrayList<ArrayList<Integer>> adj, int vis[], int parent) {
		vis[node] = 1;
		for (Integer it : adj.get(node)) {

			if (vis[it] == 0) {
				if (dfs(it, adj, vis, node) == true)
					return true;
			}

			else if (it != parent)
				return true;
		}

		return false;
	}

	// Function to detect cycle in an undirected graph.
	public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
		// Code here

		int vis[] = new int[V];
		Arrays.fill(vis, 0);

		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				vis[i] = 1;
				if (dfs(i, adj, vis, -1))
					return true;
			}
		}

		return false;
	}
}
```


**13. Distance of Nearest Cell having 1**

https://takeuforward.org/graph/distance-of-nearest-cell-having-1/

Problem Link:: https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.


Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}

Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

Solution::

```java
public class Solution {

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	// Function to find the distance of the nearest 1 in the grid for each cell.
	public int[][] nearest(int[][] grid) {
		// Code here

		int n = grid.length;
		int m = grid[0].length;

		int dist[][] = new int[n][m];
		int vis[][] = new int[n][m];

		Queue<Node> qp = new LinkedList<>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					qp.add(new Node(i, j, 0));
					vis[i][j] = 1;
				} else
					vis[i][j] = 0;
			}
		}

		while (!qp.isEmpty()) {
			int x = qp.peek().first;
			int y = qp.peek().second;
			int steps = qp.peek().third;
			qp.remove();
			dist[x][y] = steps;
			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == 0) {
					vis[newX][newY] = 1;
					qp.add(new Node(newX, newY, steps + 1));
				}
			}

		}

		return dist;
	}
}

class Node {

	int first;
	int second;
	int third;

	Node(int first, int second, int third) {
		this.first = first;
		this.second = second;
		this.third = third;
	}

}
```

**14. Surrounded Regions | Replace O’s with X’s:**

https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/

Problem Link :: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.


Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}

Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}

Explanation: 
Following the rule the above matrix is the resultant matrix. 

Solution::

```java
public class Solution {

	static int dx[] = { 1, 0, -1, 0 };
	static int dy[] = { 0, 1, 0, -1 };

	static void dfs(int x, int y, int vis[][], char a[][]) {
		vis[x][y] = 1;
		int n = a.length;
		int m = a[0].length;
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == 0 && a[newX][newY] == 'O') {
				dfs(newX, newY, vis, a);
			}
		}
	}

	static char[][] fill(int n, int m, char a[][]) {
		// code here

		int vis[][] = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && a[i][j] == 'O') {
					dfs(i, j, vis, a);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == 0 && a[i][j] == 'O')
					a[i][j] = 'X';
			}
		}
		return a;
	}
}
```


**15. Number of Enclaves**

https://takeuforward.org/graph/number-of-enclaves/

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-enclaves/1

You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}

Output:
3

Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.

Solution:: 

```java
public class Solution {

	int dx[] = { 0, 1, -1, 0 };
	int dy[] = { 1, 0, 0, -1 };

	int bfs(int x, int y, int[][] grid, int vis[][]) {
		Queue<Pair> qp = new LinkedList<>();
		vis[x][y] = 1;
		qp.add(new Pair(x, y));
		int cnt = 1;
		boolean flag = true;
		int n = grid.length;
		int m = grid[0].length;
		while (!qp.isEmpty()) {
			Pair p = qp.poll();
			for (int i = 0; i < 4; i++) {
				int newX = p.x + dx[i];
				int newY = p.y + dy[i];
				if (newX > 0 && newX < n - 1 && newY > 0 && newY < m - 1 && grid[newX][newY] == 1
						&& vis[newX][newY] == 0) {
					vis[newX][newY] = 1;
					qp.add(new Pair(newX, newY));
					cnt++;
				}
				if ((newX >= 0 && newX < n && newY >= 0 && newY < m)
						&& (newX == 0 || newX == n - 1 || newY == 0 || newY == m - 1) && grid[newX][newY] == 1
						&& vis[newX][newY] == 0) {
					vis[newX][newY] = 1;
					qp.add(new Pair(newX, newY));
					flag = false;
					cnt++;
				}
			}
		}
		if (flag == false)
			return 0;
		return cnt;
	}

	int numberOfEnclaves(int[][] grid) {

		// Your code here
		int n = grid.length;
		int m = grid[0].length;
		int vis[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i != 0 && i != n - 1 && j != 0 && j != m - 1 && grid[i][j] == 1 && vis[i][j] == 0) {
					ans += bfs(i, j, grid, vis);
				}
			}
		}

		return ans;
	}
}

class Pair {

	int x;
	int y;

	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
```

**16.  Number of Distinct Islands**

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}

Output:
1

Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Solution:: 

```java
public class Solution {

	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	public String toString(int x, int y) {
		return Integer.toString(x) + " " + Integer.toString(y);
	}

	public void dfs(int x, int y, int[][] grid, int[][] vis, List<String> lp, int r, int c) {
		vis[x][y] = 1;
		lp.add(toString(x - r, y - c));
		for (int i = 0; i < 4; i++) {
			Integer newX = x + dx[i];
			Integer newY = y + dy[i];
			if (newX >= 0 && newX < grid.length && newY >= 0 && newY < grid[0].length && vis[newX][newY] == 0
					&& grid[newX][newY] == 1) {
				dfs(newX, newY, grid, vis, lp, r, c);
			}
		}
	}

	int countDistinctIslands(int[][] grid) {

		int n = grid.length;
		int m = grid[0].length;

		int vis[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
			}
		}

		Set<List<String>> st = new HashSet<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				List<String> lp = new ArrayList<>();
				if (grid[i][j] == 1 && vis[i][j] == 0) {
					dfs(i, j, grid, vis, lp, i, j);
					st.add(lp);
				}

			}
		}
		return st.size();
	}
}
```


**17. Bipartite Graph | BFS Implementation**

https://takeuforward.org/graph/bipartite-graph-bfs-implementation/

Problem Link:: https://www.geeksforgeeks.org/problems/bipartite-graph/1

Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

Solution:: 

```java
public class Solution {

	public boolean bfs(int node, int V, ArrayList<ArrayList<Integer>> adj, int[] color) {
		color[node] = 0;
		Queue<Integer> q = new LinkedList<>();
		q.add(node);
		while (!q.isEmpty()) {
			int n = q.poll();

			for (int it : adj.get(n)) {
				if (color[it] == -1) {
					q.add(it);
					color[it] = 1 - color[n];
				} else if (color[it] == color[n])
					return false;
			}
		}

		return true;
	}

	public boolean isBipartite(int V, ArrayList<ArrayList<Integer>> adj) {
		int color[] = new int[V];
		for (int i = 0; i < V; i++) {
			color[i] = -1;
		}

		for (int i = 0; i < V; i++) {
			if (color[i] == -1) {
				if (bfs(i, V, adj, color) == false)
					return false;
			}
		}

		return true;
	}
}
```


**18. Bipartite Graph | DFS Implementation**

https://takeuforward.org/graph/bipartite-graph-dfs-implementation/

Problem Link:: https://www.geeksforgeeks.org/problems/bipartite-graph/1

Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

Solution::

```java
public class Solution {

	public boolean dfs(int node, int col, ArrayList<ArrayList<Integer>> adj, int color[]) {

		color[node] = col;
		for (int n : adj.get(node)) {
			if (color[n] == -1) {
				if (dfs(n, 1 - col, adj, color) == false)
					return false;
			} else if (color[n] == col)
				return false;
		}
		return true;

	}

	public boolean isBipartite(int V, ArrayList<ArrayList<Integer>> adj) {
		int color[] = new int[V];
		Arrays.fill(color, -1);

		for (int i = 0; i < V; i++) {
			if (color[i] == -1) {
				if (dfs(i, 0, adj, color) == false)
					return false;
			}
		}
		return true;
	}
}
```


**19. Detect cycle in a directed graph (using DFS)**

https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Solution::

```java
public class Solution {

	private boolean dfs(int node, ArrayList<ArrayList<Integer>> adj, int pathVis[], int vis[]) {

		pathVis[node] = 1;
		vis[node] = 1;

		for (int n : adj.get(node)) {
			if (vis[n] == 0) {
				if (dfs(n, adj, pathVis, vis) == true)
					return true;
			} else if (pathVis[n] == 1)
				return true;
		}
		pathVis[node] = 0;
		return false;

	}

	// Function to detect cycle in a directed graph.
	public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {

		int pathVis[] = new int[V];
		int vis[] = new int[V];
		Arrays.fill(vis, 0);
		Arrays.fill(pathVis, 0);
		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				if (dfs(i, adj, pathVis, vis) == true)
					return true;
			}
		}
		return false;
	}
}
```

**20. Find Eventual Safe States - DFS**

https://takeuforward.org/data-structure/find-eventual-safe-states-dfs-g-20/

Problem Link:: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Solution::

```java
public class Solution {

	private boolean dfs(int node, List<List<Integer>> adj, int vis[], int check[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		for (int it : adj.get(node)) {

			if (vis[it] == 0) {
				if (dfs(it, adj, vis, check, pathVis) == true)
					return true;

			} else if (pathVis[it] == 1)
				return true;
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;

	}

	List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {

		int vis[] = new int[V];
		int pathVis[] = new int[V];
		int check[] = new int[V];
		Arrays.fill(pathVis, 0);
		Arrays.fill(vis, 0);
		List<Integer> res = new ArrayList<>();
		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				dfs(i, adj, vis, check, pathVis);

			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1)
				res.add(i);
		}
		return res;
	}
}
```


**21. Topological Sort Algorithm | DFS**

https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/

Problem Link::  https://www.geeksforgeeks.org/problems/topological-sort/1

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.


In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

Solution:: 

```java
public class Solution {

	private static void dfs(int node, ArrayList<ArrayList<Integer>> adj, int vis[], Stack<Integer> st) {
		vis[node] = 1;
		for (int it : adj.get(node)) {
			if (vis[it] == 0) {
				dfs(it, adj, vis, st);
			}
		}
		st.push(node);
	}

	// Function to return list containing vertices in Topological order.
	static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
		Stack<Integer> st = new Stack<>();
		int vis[] = new int[V];
		Arrays.fill(vis, 0);

		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				dfs(i, adj, vis, st);
			}
		}

		int res[] = new int[V];
		int k = 0;
		while (!st.isEmpty()) {
			res[k++] = st.pop();
		}
		return res;
	}
}
```


**22. Kahn's Algorithm | Topological Sort Algorithm | BFS**

https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/

Problem Link:: https://www.geeksforgeeks.org/problems/topological-sort/1

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.


In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

Solution::

```java
public class Solution {

	// Function to return list containing vertices in Topological order.
	static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
		int indegree[] = new int[V];
		for (int i = 0; i < V; i++) {
			for (int it : adj.get(i)) {
				indegree[it]++;
			}
		}

		int topo[] = new int[V];
		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0)
				q.add(i);
		}
		int i = 0;
		while (!q.isEmpty()) {
			int node = q.poll();
			topo[i++] = node;
			for (int it : adj.get(node)) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.add(it);
			}

		}

		return topo;
	}
}
```


**23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm**

https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Solution::

```java
public class Solution {

	// Function to detect cycle in a directed graph.
	public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {

		int indegree[] = new int[V];
		Arrays.fill(indegree, 0);
		for (int i = 0; i < V; i++) {
			for (int it : adj.get(i)) {
				indegree[it]++;
			}
		}

		Queue<Integer> q = new LinkedList<>();

		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.add(i);
			}
		}

		while (!q.isEmpty()) {
			int node = q.poll();
			for (int it : adj.get(node)) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.add(it);
			}
		}
		for (int i = 0; i < V; i++) {
			if (indegree[i] > 0)
				return true;
		}

		return false;
	}
}
```

**24.  Course Schedule I and II | Pre-requisite Tasks | Topological Sort**

https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

Problem Link 1:: https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}

Output: Yes

Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.

Solution 1::

```java
public class Solution {

	public boolean isPossible(int N, int P, int[][] prerequisites) {
		int indegree[] = new int[N];

		ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			adj.add(i, new ArrayList<>());
		}
		for (int i = 0; i < P; i++) {
			adj.get(prerequisites[i][1]).add(prerequisites[i][0]);
		}
		Arrays.fill(indegree, 0);
		for (int i = 0; i < P; i++) {
			indegree[prerequisites[i][0]]++;
		}

		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0)
				q.add(i);
		}
		int cnt = 0;
		while (!q.isEmpty()) {
			int node = q.poll();
			cnt++;
			for (int it : adj.get(node)) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.add(it);
			}
		}
		return cnt == N ? true : false;
	}

}
```


Problem Link 2:: https://www.geeksforgeeks.org/problems/course-schedule/1ss

There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0. 


Input:
n = 2, m = 1
prerequisites = {{1, 0}}

Output: 1

Explanation:
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1 for all test cases. One possible order is [0, 1].

Solution 2::

```java
public class Solution {

	static int[] findOrder(int n, int m, ArrayList<ArrayList<Integer>> prerequisites) {
		// add your code here
		int order[] = new int[n];
		int indegree[] = new int[n];

		Arrays.fill(indegree, 0);

		ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			adj.get(prerequisites.get(i).get(1)).add(prerequisites.get(i).get(0));
		}

		for (int i = 0; i < m; i++) {
			indegree[prerequisites.get(i).get(0)]++;
		}

		Queue<Integer> q = new LinkedList<>();

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0)
				q.add(i);
		}

		int i = 0;
		while (!q.isEmpty()) {
			int node = q.poll();
			order[i++] = node;
			for (int it : adj.get(node)) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.add(it);
			}
		}
		if (i == n)
			return order;
		return new int[0];
	}

}
```


**25. Find Eventual Safe States - BFS - Topological Sort**

https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/

Problem Link:: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Solution:: 

```java
public class Solution {

	List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {

		// Your code here
		List<List<Integer>> reverse = new ArrayList<>();

		for (int i = 0; i < V; i++) {
			reverse.add(new ArrayList<>());
		}

		int indegree[] = new int[V];
		Arrays.fill(indegree, 0);
		for (int i = 0; i < V; i++) {

			for (int it : adj.get(i)) {
				reverse.get(it).add(i);
				indegree[i]++;

			}
		}

		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0)
				q.add(i);
		}
		List<Integer> topo = new ArrayList<>();
		while (!q.isEmpty()) {
			int node = q.poll();
			topo.add(node);
			for (int it : reverse.get(node)) {
				indegree[it]--;
				if (indegree[it] == 0)
					q.add(it);
			}
		}

		Collections.sort(topo);
		return topo;

	}
}
```

**26. Alien Dictionary - Topological Sort**

https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/

Problem Link:: https://www.geeksforgeeks.org/problems/alien-dictionary/1

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.


Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}

Output: 1

Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Solution::

```java
public class Solution {

	public String findOrder(String[] dict, int N, int K) {
		int indegree[] = new int[K];
		Arrays.fill(indegree, 0);
		List<List<Integer>> adj = new ArrayList<>();
		for (int i = 0; i < K; i++) {
			adj.add(new ArrayList<>());
		}
		for (int i = 0; i < dict.length - 1; i++) {
			String str1 = dict[i];
			String str2 = dict[i + 1];
			for (int j = 0; j < Math.min(str1.length(), str2.length()); j++) {
				if (str1.charAt(j) != str2.charAt(j)) {
					indegree[str2.charAt(j) - 'a']++;
					adj.get(str1.charAt(j) - 'a').add(str2.charAt(j) - 'a');
					break;
				}
			}
		}
		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i < K; i++) {
			if (indegree[i] == 0) {
				q.add(i);
			}
		}

		int cnt = 0;
		StringBuilder res = new StringBuilder();
		while (!q.isEmpty()) {
			int node = q.poll();
			cnt++;
			res.append(String.valueOf((char) (node + 'a')));
			for (int it : adj.get(node)) {
				indegree[it]--;
				if (indegree[it] == 0) {
					q.add(it);
				}
			}
		}
		if (cnt == K)
			return res.toString();
		return "";

	}
}
```

**27. Shortest Path in Directed Acyclic Graph Topological Sort**

https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/

Problem Link:: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]]

Output: 0 2 1 -1

Explanation:

Shortest path from 0 to 1 is 0->1 with edge weight 2. 

Shortest path from 0 to 2 is 0->2 with edge weight 1.

There is no way we can reach 3, so it's -1 for 3.

Solution::

```java
public class Solution {

	public int[] shortestPath(int N,int M, int[][] edges) {
	    
	    int dist[] = new int[N];
	    for(int i =0;i<N;i++){
	          dist[i] = (int)(1e9);
	    }
	    
	    int indegree[] = new int[N];
	    Arrays.fill(indegree,0);
	    List<List<Pair>> adj = new ArrayList<>();
	    for(int i =0;i<N;i++){
	        adj.add(new ArrayList<>());
	    }
	    for(int i =0;i<edges.length;i++){
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int w = edges[i][2];
	        adj.get(u).add(new Pair(v,w));
	        indegree[v]++;
	    }
	    Queue<Integer> q = new LinkedList<>();
	    for(int i =0;i<N;i++) {
	        if(indegree[i]==0){
	            q.add(i);
	        }
	    }
	    
	    dist[0] = 0;
	    while(!q.isEmpty()) {
	        int node = q.poll();
	        for(Pair it: adj.get(node)){
	          indegree[it.v]--;
	          if(dist[node]+it.w<dist[it.v]) {
	              dist[it.v] = dist[node] + it.w;
	          }
	          if(indegree[it.v] == 0){
	              q.add(it.v);
	          }
	        }
	    }
	    for(int i =0;i<N;i++) {
	        if(dist[i] == 1e9) {
	            dist[i]=-1;
	        }
	    }
	    return dist;
	}
}

class Pair {

    int v;
    int w;
    Pair(int v,int w){
        this.v = v;
        this.w = w;
    }
    
}
```


**28. Shortest Path in Undirected Graph with unit distance**

https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/

Problem Link:: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Solution::

```java
public class Solution {

	public int[] shortestPath(int[][] edges, int n, int m, int src) {

		List<List<Integer>> adj = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			adj.get(u).add(v);
			adj.get(v).add(u);
		}
		int dist[] = new int[n];
		for (int i = 0; i < n; i++) {
			dist[i] = -1;
		}

		Queue<Integer> q = new LinkedList<>();
		dist[src] = 0;
		q.add(src);
		while (!q.isEmpty()) {
			int node = q.poll();
			for (int it : adj.get(node)) {
				if (dist[it] == -1) {
					dist[it] = dist[node] + 1;
					q.add(it);
				}
			}
		}
		return dist;

	}
}
```


**29. Word Ladder - I**

https://takeuforward.org/graph/word-ladder-i-g-29/

Problem Link:: https://www.geeksforgeeks.org/problems/word-ladder/1

Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.

Only one letter can be changed in each transformation.

Each transformed word must exist in the wordList including the targetWord.

startWord may or may not be part of the wordList


Note: If no possible way to transform sequence from startWord to targetWord return 0

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",

Output: 3

Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".

Solution::

```java
public class Solution {

	public int wordLadderLength(String startWord, String targetWord, String[] wordList) {
		Set<String> st = new HashSet<>();

		for (int i = 0; i < wordList.length; i++) {
			st.add(wordList[i]);
		}

		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(startWord, 1));

		int ans = 0;
		while (!q.isEmpty()) {
			Pair p = q.poll();
			String str = p.word;
			st.remove(str);
			int level = p.level;
			for (int i = 0; i < str.length(); i++) {
				for (int j = 0; j < 26; j++) {
					String str2 = "";
					if (i != 0)
						str2 += str.substring(0, i);
					str2 += (char) (j + 'a');
					if (i != str.length() - 1)
						str2 += str.substring(i + 1);
					if (st.remove(str2) == true) {
						q.add(new Pair(str2, level + 1));
						if (str2.equals(targetWord)) {
							ans = level + 1;
							break;
						}
					}
				}
			}
		}
		return ans;
	}
}

class Pair {

	String word;
	int level;

	Pair(String word, int level) {
		this.word = word;
		this.level = level;
	}
}
```

**30. Word Ladder-II**

https://takeuforward.org/graph/g-30-word-ladder-ii/ 

Problem Link:: https://www.geeksforgeeks.org/problems/word-ladder-ii/1

Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.

Only one letter can be changed in each transformation.

Each transformed word must exist in the wordList including the targetWord.

startWord may or may not be part of the wordList.

Return an empty list if there is no such transformation sequence.



Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}

Output:
der dfr dfs
der des dfs

Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".

Solution::

```java
public class Solution {

	public ArrayList<ArrayList<String>> findSequences(String startWord, String targetWord, String[] wordList) {
		ArrayList<ArrayList<String>> sequences = new ArrayList<>();

		Set<String> st = new HashSet<>();
		for (int i = 0; i < wordList.length; i++) {
			st.add(wordList[i]);
		}

		Queue<ArrayList<String>> q = new LinkedList<>();
		ArrayList<String> ls = new ArrayList<>();
		ls.add(startWord);
		q.add(ls);
		ArrayList<String> usedOnLevel = new ArrayList<>();
		usedOnLevel.add(startWord);
		int level = 0;
		while (!q.isEmpty()) {

			ArrayList<String> top = q.peek();
			q.remove();
			if (top.size() > level) {
				level++;
				for (String it : usedOnLevel) {
					st.remove(it);
				}
			}

			String str = top.get(top.size() - 1);
			if (str.equals(targetWord)) {
				if (sequences.size() == 0) {
					sequences.add(top);
				} else if (sequences.get(0).size() == top.size()) {
					sequences.add(top);
				}
			}
			for (int j = 0; j < str.length(); j++) {
				for (int k = 0; k < 26; k++) {
					String str2 = "";
					if (j != 0)
						str2 += str.substring(0, j);
					str2 += (char) (k + 'a');
					if (j != str.length() - 1)
						str2 += str.substring(j + 1);
					if (st.contains(str2) == true) {
						top.add(str2);
						ArrayList<String> temp = new ArrayList<>(top);
						q.add(temp);
						usedOnLevel.add(str2);
						top.remove(top.size() - 1);
					}

				}
			}

		}
		return sequences;
	}
}
```


**32. Dijkstra’s Algorithm - Using Priority Queue**

https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/

Problem Link:: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.


Note: The Graph doesn't contain any negative weight cycle.

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0

Output:
0 9

Solution:: 

```java
public class Solution {

	// Function to find the shortest distance of all the vertices
	// from the source vertex S.
	static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S) {
		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.distance - b.distance);

		int dist[] = new int[V];
		for (int i = 0; i < V; i++) {
			dist[i] = (int) 1e9;
		}
		dist[S] = 0;
		pq.add(new Pair(0, S));

		while (!pq.isEmpty()) {
			Pair p = pq.poll();
			int d = p.distance;
			int n = p.node;
			for (int i = 0; i < adj.get(n).size(); i++) {
				int node = adj.get(n).get(i).get(0);
				int distance = adj.get(n).get(i).get(1);
				if (dist[node] > d + distance) {
					dist[node] = d + distance;
					pq.add(new Pair(dist[node], node));
				}
			}
		}
		return dist;

	}
}

class Pair {

	int distance;
	int node;

	Pair(int distance, int node) {
		this.distance = distance;
		this.node = node;
	}

}
```

**35. Print Shortest Path - Dijkstra’s Algorithm**

https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm/

Problem Link:: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n,  if there exists a path then return a list whose first element is the weight of the path. If no path exists then return a list containing a single element -1.


Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]

Output: 5 1 4 3 5

Explaination:
Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 

Solution::

```java
public class Solution {

	public List<Integer> shortestPath(int n, int m, int edges[][]) {

		List<Integer> path = new ArrayList<>();
		ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			adj.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			adj.get(edges[i][0]).add(new Pair(edges[i][1], edges[i][2]));
			adj.get(edges[i][1]).add(new Pair(edges[i][0], edges[i][2]));
		}

		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.first - b.first);
		int parent[] = new int[n + 1];
		int dist[] = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			dist[i] = (int) 1e9;
			parent[i] = i;
		}

		pq.add(new Pair(0, 1));
		dist[1] = 0;
		while (!pq.isEmpty()) {
			Pair p = pq.poll();
			int d = p.first;
			int node = p.second;
			for (Pair it : adj.get(node)) {
				int adjNode = it.first;
				int adjDist = it.second;
				if (d + adjDist < dist[adjNode]) {
					parent[adjNode] = node;
					dist[adjNode] = d + adjDist;
					pq.add(new Pair(d + adjDist, adjNode));
				}
			}

		}
		if (dist[n] == 1e9) {
			path.add(-1);
			return path;
		}

		int node = n;
		while (parent[node] != node) {
			path.add(node);
			node = parent[node];
		}

		path.add(1);
		path.add(dist[n]);
		Collections.reverse(path);
		return path;

	}
}

class Pair {
	int first;
	int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}
```

**36. Shortest Distance in a Binary Maze**

https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze/

Problem Link:: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.


Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}

Output: 3

Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.


Solution:: 

```java
public class Solution {

	int dx[] = { 0, 1, -1, 0 };
	int dy[] = { 1, 0, 0, -1 };

	int shortestPath(int[][] grid, int[] source, int[] destination) {

		int n = grid.length;
		int m = grid[0].length;

		int dist[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dist[i][j] = (int) 1e9;
			}
		}
		dist[source[0]][source[1]] = 0;
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(source[0], source[1]));

		while (!q.isEmpty()) {
			Pair p = q.poll();
			int x = p.first;
			int y = p.second;
			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
					if (dist[newX][newY] > dist[x][y] + 1) {
						dist[newX][newY] = dist[x][y] + 1;
						q.add(new Pair(newX, newY));
					}
				}
			}

		}

		if (dist[destination[0]][destination[1]] == 1e9)
			return -1;
		return dist[destination[0]][destination[1]];

	}
}

class Pair {
	int first;
	int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}
```

**37. Path With Minimum Effort**

https://takeuforward.org/data-structure/g-37-path-with-minimum-effort/

Problem Link:: https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.


Input:
row = 3
columns = 3 
heights = [[1,2,2],[3,8,2],[5,3,5]]

Output: 2

Explaination: 
The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.

Solution::

```java
public class Solution {

	public static int MinimumEffort(int rows, int columns, int[][] heights) {

		int n = heights.length;
		int m = heights[0].length;

		int dist[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dist[i][j] = (int) 1e9;
			}
		}

		int dx[] = { 1, 0, -1, 0 };
		int dy[] = { 0, 1, 0, -1 };
		PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.distance - b.distance);

		pq.add(new Node(0, 0, 0));

		while (!pq.isEmpty()) {
			Node node = pq.poll();
			int distance = node.distance;
			int x = node.x;
			int y = node.y;
			if (x == n - 1 && y == m - 1)
				return distance;
			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
					int effort = Math.abs(heights[newX][newY] - heights[x][y]);
					if (dist[newX][newY] > Math.max(effort, distance)) {
						dist[newX][newY] = Math.max(effort, distance);
						pq.add(new Node(dist[newX][newY], newX, newY));
					}
				}
			}

		}
		return 0;
	}
}

class Node {
	int distance;
	int x;
	int y;

	Node(int distance, int x, int y) {
		this.distance = distance;
		this.x = x;
		this.y = y;
	}
}
```

**38. Cheapest Flights Within K Stops**

https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/

Problem Link:: https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Note: The price from city A to B may be different From the price from city B to A.

Input:
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1

Output: 700

Explanation:
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.

Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


Solution::

```java
public class Solution {

	public int CheapestFLight(int n, int flights[][], int src, int dst, int k) {

		int dist[] = new int[n];
		for (int i = 0; i < n; i++) {
			dist[i] = (int) 1e9;
		}
		ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<>());

		}

		for (int i = 0; i < flights.length; i++) {
			adj.get(flights[i][0]).add(new Pair(flights[i][1], flights[i][2]));
		}
		Queue<Node> q = new LinkedList<>();
		dist[src] = 0;
		q.add(new Node(0, src, 0));
		while (!q.isEmpty()) {
			Node node = q.poll();
			int distance = node.distance;
			int source = node.source;
			int stops = node.stops;
			if (stops > k)
				continue;
			for (Pair p : adj.get(source)) {
				int adjNode = p.first;
				int adjDist = p.second;
				if (dist[adjNode] > adjDist + distance && stops <= k) {

					dist[adjNode] = distance + adjDist;
					q.add(new Node(stops + 1, adjNode, adjDist + distance));
				}
			}

		}

		return dist[dst] == 1e9 ? -1 : dist[dst];
	}
}

class Pair {
	int first;
	int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}

class Node {
	int stops;
	int source;
	int distance;

	Node(int stops, int source, int distance) {
		this.stops = stops;
		this.source = source;
		this.distance = distance;
	}
}
```


**39. Minimum Multiplications to Reach End**

https://takeuforward.org/graph/g-39-minimum-multiplications-to-reach-end/

Problem Link:: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.


Input:
arr[] = {2, 5, 7}
start = 3, end = 30

Output: 2

Explanation:

Step 1: 3*2 = 6 % 100000 = 6 

Step 2: 6*5 = 30 % 100000 = 30

Solution::

```java
public class Solution {

	int mod = 100000;

	int minimumMultiplications(int[] arr, int start, int end) {

		if (start == end) {
			return 0;
		}
		Queue<Pair> qp = new LinkedList<>();
		qp.add(new Pair(start, 0));
		int dist[] = new int[100000];
		for (int i = 0; i < 100000; i++) {
			dist[i] = (int) 1e9;
		}
		dist[start] = 0;
		while (!qp.isEmpty()) {
			Pair p = qp.poll();
			int node = p.first;
			int steps = p.second;
			for (int i = 0; i < arr.length; i++) {
				int x = (arr[i] * node) % mod;

				if (dist[x] > steps + 1) {
					dist[x] = steps + 1;
					if (x == end) {
						return steps + 1;
					}
					qp.add(new Pair(x, steps + 1));
				}
			}
		}
		return -1;

	}
}

class Pair {

	int first;
	int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}
```


**40. Number of Ways to Arrive at Destination**

https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination/

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.


Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

Output: 4

Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6

Solution::

```java
public class Solution {

	static int countPaths(int n, List<List<Integer>> roads) {

		ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<>());
		}
		for (int i = 0; i < roads.size(); i++) {
			adj.get(roads.get(i).get(0)).add(new Pair(roads.get(i).get(1), roads.get(i).get(2)));

			adj.get(roads.get(i).get(1)).add(new Pair(roads.get(i).get(0), roads.get(i).get(2)));
		}

		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.first - b.first);
		int ways[] = new int[n];
		int dist[] = new int[n];
		for (int i = 0; i < n; i++) {
			ways[i] = 0;
			dist[i] = Integer.MAX_VALUE;
		}

		pq.add(new Pair(0, 0));
		dist[0] = 0;
		ways[0] = 1;
		int mod = (int) (1e9 + 7);
		while (!pq.isEmpty()) {
			Pair p = pq.poll();
			int dis = p.first;
			int node = p.second;
			for (Pair it : adj.get(node)) {
				int adjNode = it.first;
				int adjW = it.second;
				if (dist[adjNode] > dis + adjW) {
					dist[adjNode] = dis + adjW;
					ways[adjNode] = ways[node];
					pq.add(new Pair(dist[adjNode], adjNode));
				} else if (dist[adjNode] == dis + adjW) {
					ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
				}
			}
		}

		return ways[n - 1] % mod;
	}
}

class Pair {
	int first;
	int second;

	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}
```


**41. Bellman Ford Algorithm**

https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/

Problem Link:: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

Given a weighted and directed graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be reach from the S then mark the distance as 10^8.

Note: If the Graph contains a negative cycle then return an array consisting of only -1.

Solution::

```java
public class Solution {
	static int[] bellman_ford(int V, ArrayList<ArrayList<Integer>> edges, int S) {

		int dist[] = new int[V];

		for (int i = 0; i < V; i++) {
			dist[i] = (int) 1e8;
		}
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (int j = 0; j < edges.size(); j++) {
				int u = edges.get(j).get(0);
				int v = edges.get(j).get(1);
				int w = edges.get(j).get(2);
				if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
				}
			}
		}
		for (int j = 0; j < edges.size(); j++) {
			int u = edges.get(j).get(0);
			int v = edges.get(j).get(1);
			int w = edges.get(j).get(2);
			if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
				return new int[] { -1 };
			}
		}
		return dist;

	}
}
```

**42. Floyd Warshall Algorithm**

https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/

Problem Link:: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.

Solution::

```java
public class Solution {

	public void shortest_distance(int[][] matrix) {
		int n = matrix.length;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = (int) 1e9;

				}
				if (i == j) {
					matrix[i][j] = 0;
				}
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;

				}

			}

		}
	}
}
```

**43. Find the City With the Smallest Number of Neighbours at a Threshold Distance**

https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/

Problem Link:: https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

Solution::

```java
public class Solution {

	int findCity(int n, int m, int[][] edges, int distanceThreshold) {
		// code here
		int matrix[][] = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					matrix[i][j] = 0;
				else
					matrix[i][j] = (int) 1e9;
			}
		}
		for (int i = 0; i < m; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			matrix[u][v] = w;
			matrix[v][u] = w;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i != j && matrix[i][j] <= distanceThreshold) {
					cnt++;
				}
			}
			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = i;
			}
		}
		return cityNo;
	}
}
```


**45. Prim's Algorithm - Minimum Spanning Tree**

https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/

Problem Link:: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing pairs of integers. Each pair represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Solution::

```java
public class Solution {

	static int spanningTree(int V, int E, List<List<int[]>> adj) {

		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.distance - b.distance);

		int vis[] = new int[V];
		Arrays.fill(vis, 0);
		int sum = 0;
		pq.add(new Pair(0, 0));
		while (!pq.isEmpty()) {
			Pair p = pq.poll();
			int wt = p.distance;
			int node = p.node;
			if (vis[node] == 1)
				continue;
			sum += wt;
			vis[node] = 1;
			for (int i = 0; i < adj.get(node).size(); i++) {
				int adjNode = adj.get(node).get(i)[0];
				int adjWt = adj.get(node).get(i)[1];
				if (vis[adjNode] == 0) {
					pq.add(new Pair(adjWt, adjNode));
				}
			}

		}
		return sum;
	}
}

class Pair {
	int distance;
	int node;

	Pair(int distance, int node) {
		this.distance = distance;
		this.node = node;
	}
}
```

**47. Kruskal's Algorithm - Minimum Spanning Tree**

https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/

Problem Link:: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing pairs of integers. Each pair represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Solution:: 

```java
public class Solution {
	
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
	static int spanningTree(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj) {
		List<Edge> edges = new ArrayList<Edge>();
		// O(N + E)
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < adj.get(i).size(); j++) {
				int adjNode = adj.get(i).get(j).get(0);
				int wt = adj.get(i).get(j).get(1);
				Edge temp = new Edge(i, adjNode, wt);
				edges.add(temp);
			}
		}
		DisjointSet ds = new DisjointSet(V);
		// M log M
		Collections.sort(edges);
		int mstWt = 0;
		// M x 4 x alpha x 2
		for (int i = 0; i < edges.size(); i++) {
			int wt = edges.get(i).weight;
			int u = edges.get(i).src;
			int v = edges.get(i).dest;

			if (ds.findUPar(u) != ds.findUPar(v)) {
				mstWt += wt;
				ds.unionBySize(u, v);
			}
		}

		return mstWt;
	}
}

class DisjointSet {
	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	List<Integer> size = new ArrayList<>();

	public DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			rank.add(0);
			parent.add(i);
			size.add(1);
		}
	}

	public int findUPar(int node) {
		if (node == parent.get(node)) {
			return node;
		}
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}

	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		} else if (rank.get(ulp_v) < rank.get(ulp_u)) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU + 1);
		}
	}

	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (size.get(ulp_u) < size.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
		}
	}
}

class Edge implements Comparable<Edge> {
	int src, dest, weight;

	Edge(int _src, int _dest, int _wt) {
		this.src = _src;
		this.dest = _dest;
		this.weight = _wt;
	}

	// Comparator function used for
	// sorting edgesbased on their weight
	public int compareTo(Edge compareEdge) {
		return this.weight - compareEdge.weight;
	}
};
```


**49. Number of Operations to Make Network Connected - DSU**

https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/

Problem Link:: https://www.geeksforgeeks.org/problems/connecting-the-graph/1

You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to connect the graph.
If it is not possible to connect the graph, return -1.


Input:
n = 4
m = 3
Edges = [ [0, 1] , [0, 2] , [1, 2] ]

Output: 1

Explanation:
Remove edge between vertices 1 and 2 and add between vertices 1 and 3.

Solution::

```java
public class Solution {

	public int Solve(int n, int[][] edge) {
		
		DisjointSet ds = new DisjointSet(n);
		int m = edge.length;
		int extraEdges = 0;
		for (int i = 0; i < m; i++) {
			int u = edge[i][0];
			int v = edge[i][1];
			if (ds.findUPar(u) == ds.findUPar(v)) {
				extraEdges++;
			} else {
				ds.unionByRank(u, v);
			}
		}

		int connectedComponent = 0;
		for (int i = 0; i < n; i++) {
			if (ds.findUPar(i) == i) {

				connectedComponent++;
			}
		}
		if (extraEdges >= connectedComponent - 1) {
			return connectedComponent - 1;
		}
		return -1;
	}
}

class DisjointSet {
	
	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	List<Integer> size = new ArrayList<>();

	public DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			rank.add(0);
			parent.add(i);
			size.add(1);
		}
	}

	public int findUPar(int node) {
		if (node == parent.get(node)) {
			return node;
		}
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}

	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		} else if (rank.get(ulp_v) < rank.get(ulp_u)) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU + 1);
		}
	}

	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (size.get(ulp_u) < size.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
		}
	}
}
```

**50. Accounts Merge - DSU**

https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/

Problem Link:: https://www.geeksforgeeks.org/problems/account-merge/1

Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
Geek wants you to merge these accounts. Two accounts belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts have the same name.
After merging the accounts, return the accounts in the following format: The first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.

Input:
n = 4
accounts [ ] =
[["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]

Output:
[["John","john00@mail.com","john_newyork@mail.com", "johnsmith@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]

Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com". The third John and Mary are different people as none of their email addresses are used by other accounts.We could return these arrays in any order, for example, the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Solution::

```java
public class Solution {

	static List<List<String>> accountsMerge(List<List<String>> accounts) {

		int n = accounts.size();
		DisjointSet ds = new DisjointSet(n);
		HashMap<String, Integer> mailMap = new HashMap<>();

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < accounts.get(i).size(); j++) {
				String mail = accounts.get(i).get(j);
				if (mailMap.containsKey(mail) == false) {
					mailMap.put(mail, i);
				} else {
					ds.unionByRank(i, mailMap.get(mail));
				}
			}
		}
		ArrayList<String> mergeMail[] = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			mergeMail[i] = new ArrayList<>();
		}

		for (Map.Entry<String, Integer> it : mailMap.entrySet()) {
			String mail = it.getKey();
			int node = ds.findUPar(it.getValue());
			mergeMail[node].add(mail);
		}

		List<List<String>> res = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			if (mergeMail[i].size() == 0)
				continue;
			Collections.sort(mergeMail[i]);
			List<String> temp = new ArrayList<>();
			temp.add(accounts.get(i).get(0));
			for (String str : mergeMail[i]) {
				temp.add(str);
			}
			res.add(temp);
		}

		return res;
	}
}

class DisjointSet {

	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	List<Integer> size = new ArrayList<>();

	public DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			rank.add(0);
			parent.add(i);
			size.add(1);
		}
	}

	public int findUPar(int node) {
		if (node == parent.get(node)) {
			return node;
		}
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}

	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		} else if (rank.get(ulp_v) < rank.get(ulp_u)) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU + 1);
		}
	}

	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (size.get(ulp_u) < size.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
		}
	}
}
```


**51. Number of Islands - II - Online Queries - DSU**

https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-islands/1

You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.


Solution::

```java
public class Solution {

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	public List<Integer> numOfIslands(int rows, int cols, int[][] operators) {
		DisjointSet ds = new DisjointSet(rows * cols);
		int m = operators.length;
		int vis[][] = new int[rows][cols];

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				vis[i][j] = 0;
			}
		}

		int cnt = 0;
		List<Integer> ans = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			int x = operators[i][0];
			int y = operators[i][1];
			if (vis[x][y] == 1) {
				ans.add(cnt);
				continue;
			}

			vis[x][y] = 1;
			cnt++;
			for (int j = 0; j < 4; j++) {
				int newX = x + dx[j];
				int newY = y + dy[j];
				if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && vis[newX][newY] == 1) {
					int rowNo = x * cols + y;
					int adjRowNo = newX * cols + newY;
					if (ds.findUPar(rowNo) != ds.findUPar(adjRowNo)) {
						cnt--;
						ds.unionBySize(rowNo, adjRowNo);
					}
				}
			}
			ans.add(cnt);
		}

		return ans;
	}

}

class DisjointSet {
	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	List<Integer> size = new ArrayList<>();

	public DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			rank.add(0);
			parent.add(i);
			size.add(1);
		}
	}

	public int findUPar(int node) {
		if (node == parent.get(node)) {
			return node;
		}
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}

	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		} else if (rank.get(ulp_v) < rank.get(ulp_u)) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU + 1);
		}
	}

	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (size.get(ulp_u) < size.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
		}
	}
}
```

**52. Making a Large Island - DSU**

https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/

Problem Link:: https://www.geeksforgeeks.org/problems/maximum-connected-group/1

You are given an n x n binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent to each other and both have the same value.

Input:
2
1 1
0 1

Output:
4

Explanation:
By changing cell (2,1), we can obtain a connected group of 4 1's
1 1
1 1

Solution::

```java
public class Solution {

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	public int MaxConnection(int grid[][]) {
		int n = grid.length;
		int m = grid[0].length;
		DisjointSet ds = new DisjointSet(n * m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) {
					continue;
				}
				for (int l = 0; l < 4; l++) {
					int newX = i + dx[l];
					int newY = j + dy[l];
					if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
						int nodeNo = i * m + j;
						int adjNodeNo = newX * m + newY;
						ds.unionBySize(nodeNo, adjNodeNo);
					}
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					continue;
				}
				HashSet<Integer> st = new HashSet<>();
				for (int l = 0; l < 4; l++) {
					int newX = i + dx[l];
					int newY = j + dy[l];
					if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
						int adjNodeNo = newX * m + newY;
						st.add(ds.findUPar(adjNodeNo));
					}
				}

				int sizeTotal = 0;
				for (Integer it : st) {
					sizeTotal += ds.size.get(it);
				}
				ans = Math.max(ans, sizeTotal + 1);
			}
		}

		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, ds.size.get(ds.findUPar(i)));
		}
		return ans;
	}

}

class DisjointSet {

	List<Integer> rank = new ArrayList<>();
	List<Integer> size = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();

	public DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			parent.add(i);
			size.add(1);
			rank.add(0);
		}
	}

	public int findUPar(int node) {
		if (node == parent.get(node)) {
			return node;
		}
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}

	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		} else if (rank.get(ulp_v) < rank.get(ulp_u)) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU + 1);
		}
	}

	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (size.get(ulp_u) < size.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_u) + size.get(ulp_v));
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
		}
	}
}
```


**53. Most Stones Removed with Same Row or Column - DSU**

https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/

Problem Link:: https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone.

You need to remove some stones. 

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the maximum possible number of stones that you can remove.


Input:
n=6
[[0 0] ,[ 0 1], [1 0] ,[1 2] ,[2 1] ,[2 2]]

Output:
5


One way to remove 5 stones are
1--[0,0]
2--[1,0]
3--[0,1]
4--[2,1]
5--[1,2]

Solution::

```java
public class Solution {

	int maxRemove(int[][] stones, int n) {
		int maxRow = 0;
		int maxCol = 0;
		for (int i = 0; i < n; i++) {
			maxRow = Math.max(maxRow, stones[i][0]);
			maxCol = Math.max(maxCol, stones[i][1]);
		}
		DisjointSet ds = new DisjointSet(maxRow + maxCol + 1);
		HashMap<Integer, Integer> stoneNodes = new HashMap<>();
		for (int i = 0; i < n; i++) {
			int nodeRow = stones[i][0];
			int nodeCol = stones[i][1] + maxRow + 1;
			ds.unionBySize(nodeRow, nodeCol);
			stoneNodes.put(nodeRow, 1);
			stoneNodes.put(nodeCol, 1);

		}
		int cnt = 0;

		for (Map.Entry<Integer, Integer> mp : stoneNodes.entrySet()) {
			if (ds.findUPar(mp.getKey()) == mp.getKey()) {
				cnt++;
			}
		}

		return n - cnt;
	}
};

class DisjointSet {

	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	List<Integer> size = new ArrayList<>();

	public DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			parent.add(i);
			size.add(1);
			rank.add(0);
		}
	}

	public int findUPar(int node) {
		if (node == parent.get(node)) {
			return node;
		}
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}

	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		} else if (rank.get(ulp_v) < rank.get(ulp_u)) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, 1 + rankU);

		}
	}

	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v)
			return;
		if (size.get(ulp_u) < size.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_u) + size.get(ulp_v));
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_v) + size.get(ulp_u));
		}
	}

}
```



**54. Strongly Connected Components - Kosaraju's Algorithm**

https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

Problem Link:: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Solution::

```java
public class Solution {

	private void dfs(int node, ArrayList<ArrayList<Integer>> adj, int vis[], Stack<Integer> st) {

		vis[node] = 1;
		for (int adjNode : adj.get(node)) {
			if (vis[adjNode] == 0) {
				dfs(adjNode, adj, vis, st);
			}
		}

		st.push(node);

	}

	private void dfs2(int node, ArrayList<ArrayList<Integer>> adj, int vis[]) {

		vis[node] = 1;
		for (int adjNode : adj.get(node)) {
			if (vis[adjNode] == 0) {
				dfs2(adjNode, adj, vis);
			}
		}

	}

	// Function to find number of strongly connected components in the graph.
	public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj) {
		int vis[] = new int[V];
		Stack<Integer> st = new Stack<>();

		for (int i = 0; i < V; i++) {
			vis[i] = 0;
		}

		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				dfs(i, adj, vis, st);
			}
		}

		ArrayList<ArrayList<Integer>> adjR = new ArrayList<>();
		for (int i = 0; i < V; i++) {
			adjR.add(new ArrayList<>());
		}

		for (int i = 0; i < V; i++) {
			vis[i] = 0;
			for (int it : adj.get(i)) {
				adjR.get(it).add(i);
			}
		}

		int scc = 0;
		while (!st.isEmpty()) {
			int node = st.pop();
			if (vis[node] == 0) {
				scc++;
				dfs2(node, adjR, vis);
			}
		}

		return scc;
	}
}
```


**55. Bridges in Graph - Using Tarjan's Algorithm of time in and low time**

https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/

Problem Link:: https://leetcode.com/problems/critical-connections-in-a-network/description/

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.


Solution::

```java
public class Solution {
	private int timer = 1;

	private void dfs(int node, int parent, int vis[], ArrayList<ArrayList<Integer>> adj, int tin[], int low[],
			List<List<Integer>> bridges) {

		vis[node] = 1;
		tin[node] = timer;
		low[node] = timer;
		timer++;
		for (int it : adj.get(node)) {
			if (it == parent)
				continue;
			if (vis[it] == 0) {
				dfs(it, node, vis, adj, tin, low, bridges);
				low[node] = Math.min(low[node], low[it]);
				if (low[it] > tin[node]) {
					bridges.add(Arrays.asList(it, node));
				}
			} else {
				low[node] = Math.min(low[node], low[it]);
			}

		}
	}

	public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {

		ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<>());
		}
		for (List<Integer> it : connections) {
			int u = it.get(0);
			int v = it.get(1);
			adj.get(u).add(v);
			adj.get(v).add(u);
		}
		int vis[] = new int[n];
		int tin[] = new int[n];
		int low[] = new int[n];
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
		}
		List<List<Integer>> bridges = new ArrayList<>();
		dfs(0, -1, vis, adj, tin, low, bridges);
		return bridges;
	}
}
```


**56. Articulation Point in Graph**

https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/

Problem Link:: https://www.geeksforgeeks.org/problems/articulation-point-1/1

Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Solution::

```java
public class Solution {

	private int timer = 1;
	private void dfs(int node, int parent, int vis[], int tin[], int low[], int mark[],
			ArrayList<ArrayList<Integer>> adj) {

		vis[node] = 1;
		tin[node] = low[node] = timer;
		timer++;
		int child = 0;
		for (int it : adj.get(node)) {
			if (it == parent)
				continue;
			if (vis[it] == 0) {
				dfs(it, node, vis, tin, low, mark, adj);
				low[node] = Math.min(low[node], low[it]);
				if (low[it] >= tin[node] && parent != -1) {
					mark[node] = 1;
				}
				child++;
			} else {
				low[node] = Math.min(low[node], tin[it]);
			}
		}
		if (child > 1 && parent == -1) {
			mark[node] = 1;
		}

	}

	public ArrayList<Integer> articulationPoints(int V, ArrayList<ArrayList<Integer>> adj) {

		int vis[] = new int[V];
		int mark[] = new int[V];
		int tin[] = new int[V];
		int low[] = new int[V];

		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				dfs(i, -1, vis, tin, low, mark, adj);
			}
		}

		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = 0; i < V; i++) {
			if (mark[i] == 1) {
				ans.add(i);
			}
		}
		if (ans.size() == 0) {
			ans.add(-1);
		}
		return ans;
	}
}
```