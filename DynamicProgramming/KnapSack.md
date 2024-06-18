**Base Condition--> Think of its smallest valid input.**

**Recursive Approach::**

```java
public class Solution {

	int knapsack(int wt[], int val[], int w, int n) {

		// Base Condition
		if (n == 0 || w == 0)
			return 0;
		if (wt[n - 1] <= w)
			return Math.max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));

		return knapsack(wt, val, w, n - 1);
	}
}
```

**Memoization Approach::**

Create a global matrix of the size according to the constraints of n and w. and initialize it with -1.


```java
public class Solution {

	int t[][] = new int[1000001][1000001];

	int knapsack(int wt[], int val[], int w, int n) {
		// Base Condition
		if (n == 0 || w == 0)
			return 0;
		if (t[n][w] != -1)
			return t[n][w];
		if (wt[n - 1] <= w)
			return t[n][w] = Math.max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
					knapsack(wt, val, w, n - 1));

		return t[n][w] = knapsack(wt, val, w, n - 1);

	}
}
```


**Top Down Approach**

Base condition will be used to initilization

```java
public class Solution {

	int t[][] = new int[1000001][100001];

	int knapsack(int wt[], int val[], int w, int n) {

		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < w + 1; j++)
				if (i == 0 || j == 0)
					t[i][j] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= w; j++) {
				if (wt[i - 1] <= j)
					t[i][j] = Math.max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
				else
					t[i][j] = t[i - 1][j];
			}
		}
		return t[n][w];
	}
}
```


**0/1 KnapSack Problem Solution**

https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

```java
public class Solution {
	
	static int knapSack(int W, int wt[], int val[], int n, int[][] t) {
		if (n == 0 || W == 0)
			return t[n][W] = 0;
		if (t[n][W] != -1)
			return t[n][W];
		if (wt[n - 1] <= W)
			return t[n][W] = Math.max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1, t),
					knapSack(W, wt, val, n - 1, t));
		else
			return t[n][W] = knapSack(W, wt, val, n - 1, t);
	}

	// Function to return max value that can be put in knapsack of capacity W.
	static int knapSack(int W, int wt[], int val[], int n) {

		int t[][] = new int[n + 1][W + 1];

		for (int i = 0; i < t.length; i++) {
			for (int j = 0; j < t[i].length; j++) {
				t[i][j] = -1;
			}
		}
		return knapSack(W, wt, val, n, t);
		// for(int i=0;i<=n;i++)
		// {
		// for(int j=0;j<=W;j++)
		// {
		// if(i==0||j==0)
		// t[i][j]=0;
		// else
		// {
		// if(wt[i-1]<=j)
		// t[i][j]=Math.max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
		// else
		// t[i][j]=t[i-1][j];
		// }
		// }

		// }

		// return t[n][W];
	}
}
```

# Problems Related to KnapSack


**1. Subset Sum Problem**

https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


```java
public class Solution {

	static int isSubsetSum(int N, int arr[], int sum, int t[][]) {
		if (N == 0 && sum > 0)
			return 0;
		if (N >= 0 && sum == 0)
			return 1;
		if (t[N][sum] != -1)
			return t[N][sum];
		if (arr[N - 1] <= sum)
			return t[N][sum] = Math.max(isSubsetSum(N - 1, arr, sum - arr[N - 1], t), isSubsetSum(N - 1, arr, sum, t));
		return t[N][sum] = isSubsetSum(N - 1, arr, sum, t);
	}

	static Boolean isSubsetSum(int N, int arr[], int sum) {

		int t[][] = new int[N + 1][sum + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= sum; j++)
				t[i][j] = -1;
		}
		// code here
		return isSubsetSum(N, arr, sum, t) == 1 ? true : false;

	}
}
```



**2. Equal sum partition**

https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1


```java
public class Solution {

	static int equalPartition(int N, int arr[], int sum, int t[][]) {
		if (N == 0)
			return 0;
		if (sum == 0)
			return 1;
		if (t[N][sum] != -1)
			return t[N][sum];
		if (arr[N - 1] <= sum)
			return t[N][sum] = Math.max(equalPartition(N - 1, arr, sum - arr[N - 1], t),
					equalPartition(N - 1, arr, sum, t));
		else
			return t[N][sum] = equalPartition(N - 1, arr, sum, t);
	}

	static int equalPartition(int N, int arr[]) {

		// code here
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr[i];
		if (sum % 2 != 0)
			return 0;
		int t[][] = new int[N + 1][sum / 2 + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= sum / 2; j++)
				t[i][j] = -1;
		}
		return equalPartition(N, arr, sum / 2, t);
	}
}
```


**3. Count of subset sum**

https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1


```java
public class Solution {

	public static final int mod = 1000000007;

	public int perfectSum(int arr[], int n, int sum, int t[][]) {
		if (sum == 0 && n == 0)
			return 1;
		if (n == 0)
			return 0;
		if (t[n][sum] != -1)
			return t[n][sum] % mod;
		if (arr[n - 1] <= sum)
			return t[n][sum] = (perfectSum(arr, n - 1, sum - arr[n - 1], t) + perfectSum(arr, n - 1, sum, t)) % mod;
		else
			return t[n][sum] = perfectSum(arr, n - 1, sum, t) % mod;
	}

	public int perfectSum(int arr[], int n, int sum) {
		// Your code goes here
		int t[][] = new int[n + 1][sum + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= sum; j++) {
				t[i][j] = -1;
			}
		}

		return perfectSum(arr, n, sum, t) % mod;

	}
}
```


**4. Minimum Subset sum Diff**

https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1


```java
public class Solution {
	
	int minAns = Integer.MAX_VALUE;

	public void minDifference(int arr[], int n, int sum1, int sum2, int t[][]) {
		if (n == 0 || sum2 == 0)
			return;
		if (t[n][sum2] != -1)
			return;
		else {
			minAns = Math.min(minAns, Math.abs(sum1 - sum2));
			minDifference(arr, n - 1, sum1 + arr[n - 1], sum2 - arr[n - 1], t);
			minAns = Math.min(minAns, Math.abs(sum1 - sum2));
			t[n][sum2] = minAns;
			minDifference(arr, n - 1, sum1, sum2, t);
			minAns = Math.min(minAns, Math.abs(sum1 - sum2));
			t[n][sum2] = minAns;
		}

	}

	public int minDifference(int arr[], int n) {
		// Your code goes here
		int sum2 = 0;
		for (int i = 0; i < n; i++)
			sum2 += arr[i];
		int t[][] = new int[n + 1][sum2 + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= sum2; j++) {
				t[i][j] = -1;
			}
		}
		int sum1 = 0;
		minDifference(arr, n, sum1, sum2, t);
		return minAns;

	}
}
```


**5. Target Sum**

https://leetcode.com/problems/target-sum/


```java
public class Solution {

	public int findTargetSumWays(int nums[], int n, int sum, int[][] t) {
		if (sum == 0 && n == 0)
			return 1;
		if (n == 0)
			return 0;
		if (t[n][sum] != -1)
			return t[n][sum];
		if (nums[n - 1] <= sum)
			return t[n][sum] = findTargetSumWays(nums, n - 1, sum - nums[n - 1], t)
					+ findTargetSumWays(nums, n - 1, sum, t);
		return t[n][sum] = findTargetSumWays(nums, n - 1, sum, t);

	}

	public int findTargetSumWays(int[] nums, int target) {

		int n = nums.length;
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += nums[i];
		if (sum < target || (sum - target) % 2 == 1)
			return 0;
		sum = (sum - target) / 2;
		int t[][] = new int[n + 1][sum + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= sum; j++) {
				t[i][j] = -1;
			}
		}
		return findTargetSumWays(nums, n, sum, t);

	}
}
```

**6. Number of subset with given difference**

https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1


```java
public class Solution {

	public static final int mod = 1000000007;

	public int countPartitions(int arr[], int n, int sum, int t[][]) {
		if (sum == 0 && n == 0)
			return 1;
		if (n == 0)
			return 0;
		if (t[n][sum] != -1)
			return t[n][sum] % mod;
		if (arr[n - 1] <= sum)
			return t[n][sum] = (countPartitions(arr, n - 1, sum - arr[n - 1], t) + countPartitions(arr, n - 1, sum, t))
					% mod;
		else
			return t[n][sum] = countPartitions(arr, n - 1, sum, t) % mod;

	}

	public int countPartitions(int n, int d, int arr[]) {
		// Code here

		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		if (sum < d || (sum + d) % 2 == 1)
			return 0;

		sum = (sum + d) / 2;
		int t[][] = new int[n + 1][sum + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= sum; j++) {
				t[i][j] = -1;
			}
		}
		return countPartitions(arr, n, sum, t) % mod;
	}
}
```