1. Introduction to Graph: https://takeuforward.org/graph/introduction-to-graph/

2. Graph Representation: https://takeuforward.org/graph/graph-representation-in-c/

3. Connected Components in Graphs: https://takeuforward.org/graph/connected-components-in-graphs/

4. Breadth First Search (BFS): Level Order Traversal: https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/

Problem Link:: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Solution:: 

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

6. Depth First Search (DFS): https://takeuforward.org/data-structure/depth-first-search-dfs/

Problem Link:: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Solution:: 

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

7. Number of Provinces: https://takeuforward.org/data-structure/number-of-provinces/

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-provinces/1

Solution::

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

8. Number of Islands | Number of Connected Components in Matrix

Problem Link:: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

Solution::

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


9. Flood Fill Algorithm - Graphs: https://takeuforward.org/graph/flood-fill-algorithm-graphs/

Problem Link:: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

Solution::

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



10. Rotten Oranges: https://takeuforward.org/data-structure/rotten-oranges/

Problem Link:: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

Solution::

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




11. Detect Cycle in an Undirected Graph (using BFS): https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Solution::

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


12. Detect Cycle in an Undirected Graph (using DFS): https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Solution::

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


13. Distance of Nearest Cell having 1: https://takeuforward.org/graph/distance-of-nearest-cell-having-1/

Problem Link:: https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

Solution::

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

14. Surrounded Regions | Replace O’s with X’s: https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/

Problem Link :: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

Solution::

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


15. Number of Enclaves: https://takeuforward.org/graph/number-of-enclaves/

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-enclaves/1

Solution:: 

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

16.  Number of Distinct Islands

Problem Link:: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

Solution:: 

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


17. Bipartite Graph | BFS Implementation: https://takeuforward.org/graph/bipartite-graph-bfs-implementation/

Problem Link:: https://www.geeksforgeeks.org/problems/bipartite-graph/1

Solution:: 

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


18. Bipartite Graph | DFS Implementation: https://takeuforward.org/graph/bipartite-graph-dfs-implementation/

Problem Link:: https://www.geeksforgeeks.org/problems/bipartite-graph/1

Solution::

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


19. Detect cycle in a directed graph (using DFS): https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Solution::

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


20. Find Eventual Safe States - DFS: https://takeuforward.org/data-structure/find-eventual-safe-states-dfs-g-20/

Problem Link:: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

Solution::

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


21. Topological Sort Algorithm | DFS: https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/

Problem Link::  https://www.geeksforgeeks.org/problems/topological-sort/1

Solution:: 

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


22. Kahn's Algorithm | Topological Sort Algorithm | BFS: https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/

Problem Link:: https://www.geeksforgeeks.org/problems/topological-sort/1

Solution::

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


23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm: https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/

Problem Link:: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Solution::

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

24.  Course Schedule I and II | Pre-requisite Tasks | Topological Sort: https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

Problem Link 1:: https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

Solution 1::

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


Problem Linl 2:: https://www.geeksforgeeks.org/problems/course-schedule/1ss

Solution 2::

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


25. Find Eventual Safe States - BFS - Topological Sort: https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/

Problem Link:: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

Solution:: 

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

26. Alien Dictionary - Topological Sort: https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/

Problem Link:: https://www.geeksforgeeks.org/problems/alien-dictionary/1

Solution::

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

