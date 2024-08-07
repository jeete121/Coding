**Multiple occurrences allowed**

**Recursive Approach**

```java
public class Solution {

	int knapsack(int wt[], int val[], int w, int n) {
		// Base Condition
		if (n == 0 || w == 0)
			return 0;
		if (wt[n - 1] <= w)
			return Math.max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n), knapsack(wt, val, w, n - 1));
		else
			return knapsack(wt, val, w, n - 1);
	}
}
```


**Memoization Approach**

Create a global matrix of the size according to the constraints of n and w. and initialize it with -1.

```java
public class Solution {

	int t[][] = new int[100001][100001];

	int knapsack(int wt[], int val[], int w, int n) {
		// Base Condition
		if (n == 0 || w == 0)
			return 0;
		if (t[n][w] != -1)
			return t[n][w];
		if (wt[n - 1] <= w)
			return t[n][w] = Math.max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n), knapsack(wt, val, w, n - 1));
		else
			return t[n][w] = knapsack(wt, val, w, n - 1);
	}

}
```


**Top Down Approach**

Base condition will be used to initilization

```java
public class Solution {

	int knapsack(int wt[], int val[], int w, int n) {

		int t[][] = new int[n + 1][w + 1];

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < w + 1; j++) {
				if (i == 0 || j == 0)
					t[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= w; j++) {
				if (wt[i - 1] <= j)
					t[i][j] = Math.max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
				else
					t[i][j] = t[i - 1][j];
			}
		}
		return t[n][w];
	}

}

```


**Unbounded KnapSack Problem**

https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Input: 
N = 2
W = 3
val = {1, 1}
wt = {2, 1}
Output: 
3

Explanation: 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.

```java
public class Solution {
	
	static int knapSack(int N, int W, int val[], int wt[], int t[][]) {
		if (N == 0 || W == 0)
			return 0;
		if (t[N][W] != -1)
			return t[N][W];
		if (wt[N - 1] <= W)
			return t[N][W] = Math.max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt, t),
					knapSack(N - 1, W, val, wt, t));
		return t[N][W] = knapSack(N - 1, W, val, wt, t);
	}

	static int knapSack(int N, int W, int val[], int wt[]) {

		int t[][] = new int[N + 1][W + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= W; j++) {
				t[i][j] = -1;
			}
		}
		return knapSack(N, W, val, wt, t);

	}
}
```

# Related Problems

**1. Rod Cutting**

https://www.geeksforgeeks.org/problems/rod-cutting0840/1

Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output: 22

Explanation:
The maximum obtainable value is 22 by 
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.


```java
public class Solution {

	public int cutRod(int val[], int wt[], int n, int w, int t[][]) {
		if (n == 0 || w == 0)
			return 0;
		if (t[n][w] != -1)
			return t[n][w];
		if (wt[n - 1] <= w)
			return t[n][w] = Math.max(val[n - 1] + cutRod(val, wt, n, w - wt[n - 1], t), cutRod(val, wt, n - 1, w, t));
		return t[n][w] = cutRod(val, wt, n - 1, w, t);
	}

	public int cutRod(int price[], int n) {

		int length[] = new int[n];
		for (int i = 0; i < n; i++)
			length[i] = i + 1;
		int t[][] = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return cutRod(price, length, n, n, t);
	}
}
```

**2. Coin Change I**

https://www.geeksforgeeks.org/problems/coin-change2448/1

Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4

Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.


```java
public class Solution {

	public long count(int coins[], int N, int sum, long t[][]) {
		if (sum == 0)
			return 1;
		if (N == 0)
			return 0;
		if (t[N][sum] != -1)
			return t[N][sum];
		if (coins[N - 1] <= sum)
			return t[N][sum] = count(coins, N, sum - coins[N - 1], t) + count(coins, N - 1, sum, t);
		return t[N][sum] = count(coins, N - 1, sum, t);
	}

	public long count(int coins[], int N, int sum) {

		long t[][] = new long[N + 1][sum + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= sum; j++) {
				t[i][j] = -1L;
			}
		}
		return count(coins, N, sum, t);
	}
}
```

**3. Coin Change II**

https://www.geeksforgeeks.org/problems/number-of-coins1824/1

Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2

Explanation: Use one 25 cent coin
and one 5 cent coin

```java
public class Solution {

	public int minCoins(int coins[], int M, int V, int t[][]) {
		if (V == 0)
			return 0;
		if (M == 0)
			return Integer.MAX_VALUE - 1;
		if (t[M][V] != -1)
			return t[M][V];
		if (coins[M - 1] <= V)
			return t[M][V] = Math.min(1 + minCoins(coins, M, V - coins[M - 1], t), minCoins(coins, M - 1, V, t));
		return t[M][V] = minCoins(coins, M - 1, V, t);
	}

	public int minCoins(int coins[], int M, int V) {

		int t[][] = new int[M + 1][V + 1];
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= V; j++) {
				t[i][j] = -1;
			}
		}
		int res = minCoins(coins, M, V, t);
		return res == Integer.MAX_VALUE - 1 ? -1 : res;

	}
}
```

**4. Maximum Ribbon Cut**

https://www.geeksforgeeks.org/problems/max-rope-cutting1312/1

Given a rope of length N meters, cut the rope into several ropes of varying lengths in a way that maximizes product of lengths of all resulting ropes. You must make at least one cut.

Example 1:

Input:
N = 2
Output: 1

Explanation: Since 1 cut is mandatory.
Maximum obtainable product is 1*1 = 1.

Example 2:

Input:
N = 5
Output: 6

Explanation: 
Maximum obtainable product is 2*3 = 6.

```java
public class Solution {

	long maxProduct(int n, int arr[], int w, long t[][]) {
		if (n == 1 || w == 0)
			return 1;
		if (t[n][w] != -1)
			return t[n][w];
		if (arr[n - 1] <= w)
			return t[n][w] = Math.max(arr[n - 1] * maxProduct(n, arr, w - arr[n - 1], t), maxProduct(n - 1, arr, w, t));
		return t[n][w] = maxProduct(n - 1, arr, w, t);

	}

	long maxProduct(int n) {

		if (n == 1)
			return 0;

		int arr[] = new int[n + 1];
		for (int i = 1; i <= n; i++)
			arr[i] = i;
		long t[][] = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return maxProduct(n, arr, n, t);
	}
}
```