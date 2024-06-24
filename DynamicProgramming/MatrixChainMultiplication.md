# General Format

```java
public class Solution {

	int ans = 0;

	int solve(int arr[], int i, int j) {
		if (i > j)
			return 0;

		for (int k = i; k < j; k++) {
			// calculate temporary ans

			tempAns = solve(arr, i, k) + solve(arr, k + 1, j);
			// in the above line + means any function.
			ans = fun(tempAns);
		}

		return ans;
	}

}
```

# Matrix Chain Multiplication Related Problems


**1. Matrix Chain Multiplication (MCM)**

https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).


Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explanation: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Recursion

```java
public class Solution {

	static int solve(int arr[], int i, int j) {
		if (i >= j)
			return 0;
		int ans = Integer.MAX_VALUE;
		for (int k = i; k <= j - 1; k++) {
			int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
			ans = Math.min(ans, tempAns);
		}
		return ans;
	}

	static int matrixMultiplication(int N, int arr[]) {
		return solve(arr, 1, N - 1);
	}
}
```


Memoization

```java
public class Solution {

	static int t[][];

	static int solve(int arr[], int i, int j) {
		if (i >= j)
			return 0;
		int ans = Integer.MAX_VALUE;
		if (t[i][j] != -1)
			return t[i][j];
		for (int k = i; k <= j - 1; k++) {
			int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
			t[i][j] = ans = Math.min(ans, tempAns);
		}
		return t[i][j];
	}

	static int matrixMultiplication(int N, int arr[]) {
		t = new int[N + 1][N + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				t[i][j] = -1;
			}
		}
		return solve(arr, 1, N - 1);
	}
}
```


**2. Printing MCM**

**3. Evaluate Expression to True/Boolean Parenthesis**

https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

Given a boolean expression s of length n with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer can be large, so return it with modulo 1003

Input: 
n = 7
s = T|T&F^T
Output: 
4
Explaination: 
The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

Recursive

```java
public class Solution {

	static int solve(String s, int i, int j, boolean isTrue) {
		if (i > j)
			return 0;
		if (i == j) {
			if (isTrue)
				return s.charAt(i) == 'T' ? 1 : 0;
			else
				return s.charAt(i) == 'F' ? 1 : 0;
		}
		int ans = 0;
		for (int k = i + 1; k <= j - 1; k += 2) {
			int lt = solve(s, i, k - 1, true);
			int lf = solve(s, i, k - 1, false);
			int rt = solve(s, k + 1, j, true);
			int rf = solve(s, k + 1, j, false);
			if (s.charAt(k) == '&') {
				if (isTrue)
					ans = ans + lt * rt;
				else
					ans = ans + lt * rf + lf * rf + lf * rt;
			} else if (s.charAt(k) == '|') {
				if (isTrue)
					ans = ans + lt * rt + lt * rf + lf * rt;
				else
					ans = ans + lf * rf;
			} else {
				if (isTrue)
					ans = ans + rt * lf + rf * lt;
				else
					ans = ans + rf * lf + rt * lt;
			}
		}
		return ans;
	}

	static int countWays(int n, String s) {

		return solve(s, 0, n - 1, true);

	}
}
```


Memoization

```java
public class Solution {

	static int t[][][];
	static int mod = 1003;

	static int solve(String s, int i, int j, boolean isTrue) {
		if (i > j)
			return 0;
		if (i == j) {
			if (isTrue)
				return t[i][j][0] = s.charAt(i) == 'T' ? 1 : 0;
			else
				return t[i][j][1] = s.charAt(i) == 'F' ? 1 : 0;
		}
		if (isTrue && t[i][j][0] != -1)
			return t[i][j][0];
		if (!isTrue && t[i][j][1] != -1)
			return t[i][j][1];
		int ans = 0;
		for (int k = i + 1; k <= j - 1; k += 2) {
			int lt = solve(s, i, k - 1, true) % mod;
			int lf = solve(s, i, k - 1, false) % mod;
			int rt = solve(s, k + 1, j, true) % mod;
			int rf = solve(s, k + 1, j, false) % mod;
			if (s.charAt(k) == '&') {
				if (isTrue)
					ans = (ans + (lt * rt) % mod) % mod;
				else
					ans = (ans + (lt * rf) % mod + (lf * rf) % mod + (lf * rt) % mod) % mod;
			} else if (s.charAt(k) == '|') {
				if (isTrue)
					ans = (ans + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
				else
					ans = (ans + (lf * rf) % mod) % mod;
			} else {
				if (isTrue)
					ans = (ans + (rt * lf) % mod + (rf * lt) % mod) % mod;
				else
					ans = (ans + (rf * lf) % mod + (rt * lt) % mod) % mod;
			}
		}
		if (isTrue)
			return t[i][j][0] = ans;
		else
			return t[i][j][1] = ans;
	}

	static int countWays(int n, String s) {

		t = new int[n + 1][n + 1][2];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j][0] = -1;
				t[i][j][1] = -1;
			}
		}
		return solve(s, 0, n - 1, true) % mod;

	}
}
```

**4. Min/Max Value of an Expression**


**5. Palindrome Partitioning**

https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

Input: str = "ababbbabbababa"
Output: 3

Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

Recursion

```java
public class Solution {

	static boolean isPalindrome(String str, int i, int j) {
		while (i < j) {
			if (str.charAt(i) != str.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}

	static int solve(String str, int i, int j) {
		if (i >= j)
			return 0;
		if (isPalindrome(str, i, j))
			return 0;
		int ans = Integer.MAX_VALUE;
		for (int k = i; k < j; k++) {
			int tempAns = solve(str, i, k) + solve(str, k + 1, j) + 1;
			ans = Math.min(ans, tempAns);
		}
		return ans;
	}

	static int palindromicPartition(String str) {

		int n = str.length();
		return solve(str, 0, n - 1);
	}
}
```


Memoization


```java
public class Solution {

	static int t[][];

	static boolean isPalindrome(String str, int i, int j) {
		while (i < j) {
			if (str.charAt(i) != str.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}

	static int solve(String str, int i, int j) {
		if (i >= j)
			return 0;
		if (isPalindrome(str, i, j))
			return 0;
		if (t[i][j] != -1)
			return t[i][j];
		int ans = Integer.MAX_VALUE;
		for (int k = i; k < j; k++) {
			int tempAns = solve(str, i, k) + solve(str, k + 1, j) + 1;
			ans = Math.min(ans, tempAns);
		}
		return t[i][j] = ans;
	}

	static int palindromicPartition(String str) {

		int n = str.length();
		t = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return solve(str, 0, n - 1);
	}
}
```


Optimized Code

```java
public class Solution {

	static int t[][];

	static boolean isPalindrome(String str, int i, int j) {
		while (i < j) {
			if (str.charAt(i) != str.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}

	static int solve(String str, int i, int j) {
		if (i >= j)
			return 0;
		if (t[i][j] != -1)
			return t[i][j];
		if (isPalindrome(str, i, j))
			return 0;
		int ans = Integer.MAX_VALUE;
		for (int k = i; k < j; k++) {
			int x, y;
			if (t[i][k] != -1)
				x = t[i][k];
			else {
				x = solve(str, i, k);
				t[i][k] = x;
			}
			if (t[k + 1][j] != -1)
				y = t[k + 1][j];
			else {
				y = solve(str, k + 1, j);
				t[k + 1][j] = y;
			}
			int tempAns = x + y + 1;
			ans = Math.min(ans, tempAns);
		}
		return t[i][j] = ans;
	}

	static int palindromicPartition(String str) {

		int n = str.length();
		t = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return solve(str, 0, n - 1);
	}
}
```


**6. Scramble String**

https://leetcode.com/problems/scramble-string/

We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

Recursion

```java
public class Solution {
	
	public boolean solve(String a, String b) {
		if (a.equals(b))
			return true;
		if (a.length() == 1)
			return false;
		boolean ans = false;
		for (int i = 1; i < b.length(); i++) {
			// CASE I SWAP
			int n = b.length();
			boolean tempAns = ((solve(a.substring(0, i), b.substring(n - i))
					&& solve(a.substring(i), b.substring(0, n - i)))) ||
			// CASE II NO SWAP
					(solve(a.substring(0, i), b.substring(0, i)) && solve(a.substring(i), b.substring(i)));
			ans = tempAns || ans;
		}
		return ans;
	}

	public boolean isScramble(String s1, String s2) {

		return solve(s1, s2);

	}
}
```

Memoization

```java
public class Solution {

	Map<String, Integer> mp;

	public boolean solve(String a, String b) {
		if (a.equals(b))
			return true;
		if (a.length() == 1)
			return false;
		if (mp.getOrDefault(a + " " + b, -1) != -1)
			return (mp.get(a + " " + b) == 1) ? true : false;
		int n = a.length();
		boolean ans = false;
		for (int i = 1; i < n; i++) {
			// CASE I SWAP
			boolean tempAns = ((solve(a.substring(0, i), b.substring(n - i))
					&& solve(a.substring(i), b.substring(0, n - i)))) ||
			// CASE II NO SWAP
					(solve(a.substring(0, i), b.substring(0, i)) && solve(a.substring(i), b.substring(i)));
			ans = tempAns || ans;
		}
		mp.put(a + " " + b, (ans == true) ? 1 : 0);
		return ans;
	}

	public boolean isScramble(String s1, String s2) {

		mp = new HashMap<>();
		return solve(s1, s2);

	}
}
```

**7. Egg Dropping Problem**

https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input: N = 2, K = 10
Output: 4

```java
public class Solution {

	static int t[][];

	static int solve(int n, int f) {
		if (n == 1 || f <= 1)
			return f;
		if (t[n][f] != -1)
			return t[n][f];
		int ans = Integer.MAX_VALUE;
		for (int k = 1; k <= f; k++) {
			int tempAns = 1 + Math.max(solve(n - 1, k - 1), solve(n, f - k));
			ans = Math.min(ans, tempAns);
		}
		return t[n][f] = ans;
	}

	static int eggDrop(int n, int k) {

		t = new int[n + 1][k + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				t[i][j] = -1;
			}
		}
		return solve(n, k);

	}
}
```