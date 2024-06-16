General Format::

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


1. Matrix Chain Multiplication (MCM)(https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

2. Printing MCM

3. Evaluate Expression to True/Boolean Parenthesis (https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1)

4. Min/Mac Value of an Expression

5. Palindrome Partitioning (https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1)

6. Scramble String (https://leetcode.com/problems/scramble-string/)

7. Egg Dropping Problem (https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1)


1. Matrix Chain Multiplication (MCM)

Recursion::

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


Memoization::

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


3. Evaluate Expression to True/Boolean Parenthesis

Recurssive

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


Memoization

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

5. Palindrome Partitioning

Recursion::

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

Memoization::

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


Optimized Code::

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


6. Scramble String

Recursion::

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

Memoization::

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

7. Egg Dropping Problem

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