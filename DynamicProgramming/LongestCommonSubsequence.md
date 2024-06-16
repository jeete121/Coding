Longest Common Subsequence

Recursive Approach::

public class Solution {

	int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return 1 + LCS(X, Y, n - 1, m - 1);
		return Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));

	}
}


Memoized Approach::

public class Solution {

	int t[][] = new int[1001][1001];

	int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));

	}
}


Top Down Approach::

public class Solution {

	int LCS(String X, String Y, int n, int m) {

		int t[][] = new int[n + 1][m + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {

				if (i == 0 || j == 0)
					return t[i][j] = 0;
				else {
					if (X.charAt(i - 1) == Y.charAt(j - 1))
						t[i][j] = 1 + t[i - 1][j - 1];
					else
						t[i][j] = Math.max(t[i - 1][j], t[i][j - 1]);
				}
			}
		}
		return t[n][m];
	}
}



Related Problems::
1. Longest Common Substring (https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

2. Print LCS

3. Shortest Common SuperSequence (https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1)

4. Print SCS (https://leetcode.com/problems/shortest-common-supersequence/description/)

5. Minimum no. of insertion and deletion a-> b
(https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1)

6. Longest Repeating subsequence (https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)

7. Length of Longest subsequence of a which is a substring of b.

8. Subsequence pattern matching (https://leetcode.com/problems/is-subsequence/description/)

9. Count how many times a appear as subsequence in b

10. Longest Palindromic Subsequence (https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1)

11. Longest Palindromic substring

12. Count of Palindromic substring

13. Minimum no. of deletion in a string to make it a palindrome.
(https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1)

14. Minimum no. of insertion in a string to make it a palindrome. (https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1)




1. Longest Common Substring 

public class Solution {

	int t[][] = new int[1001][1001];

	int longestCommonSubstr(String S1, String S2, int n, int m) {
		// code here
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 || j == 0)
					t[i][j] = 0;
				else {
					if (S1.charAt(i - 1) == S2.charAt(j - 1)) {
						t[i][j] = 1 + t[i - 1][j - 1];
					} else
						t[i][j] = 0;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				ans = Math.max(ans, t[i][j]);
			}
		}

		return ans;
	}
}

2. Print LCS

public class Solution {

	public String printLCS(String X, String Y, int n, int m) {

		int t[][] = new int[n + 1][m + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 || j == 0)
					t[i][j] = 0;
				else {
					if (X.charAt(i - 1) == Y.charAt(j - 1))
						t[i][j] = 1 + t[i - 1][j - 1];
					else
						t[i][j] = Math.max(t[i - 1][j], t[i][j - 1]);
				}
			}
		}

		int i = n, j = m;
		String res = "";
		while (i > 0 && j > 0) {
			if (X.charAt(i - 1) == Y.charAt(j - 1)) {
				res = X.charAt(i - 1) + res;
				i--;
				j--;
			} else {
				if (t[i - 1][j] > t[i][j - 1])
					i--;
				else
					j--;
			}
		}
		return res;
	}
}

public class Solution {

	public int t[][] = new int[1001][1001];

	// Recursion + Memoization
	public int longestCommonSubsequence(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + longestCommonSubsequence(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(longestCommonSubsequence(X, Y, n - 1, m), longestCommonSubsequence(X, Y, n, m - 1));
	}

	public String printLCS(String X, String Y, int n, int m) {
		longestCommonSubsequence(X, Y, n, m);
		int i = n, j = m;
		String res = "";
		while (i > 0 && j > 0) {
			if (X.charAt(i - 1) == Y.charAt(j - 1)) {
				res = X.charAt(i - 1) + res;
				i--;
				j--;
			} else {
				if (t[i - 1][j] > t[i][j - 1])
					i--;
				else
					j--;
			}
		}
		return res;
	}

	public String longestCommonSubsequence(String text1, String text2) {

		int n = text1.length(), m = text2.length();

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				t[i][j] = -1;
			}
		}

		String str = printLCS(text1, text2, n, m);
		return str;

	}

}


3. Shortest Common SuperSequence

public class Solution {

	public static int t[][];

	public static int LCS(String X, String Y, int m, int n) {
		if (n == 0 || m == 0)
			return 0;
		if (t[m][n] != -1)
			return t[m][n];
		if (X.charAt(m - 1) == Y.charAt(n - 1))
			return t[m][n] = 1 + LCS(X, Y, m - 1, n - 1);
		return t[m][n] = Math.max(LCS(X, Y, m - 1, n), LCS(X, Y, m, n - 1));
	}

	// Function to find length of shortest common supersequence of two strings.
	public static int shortestCommonSupersequence(String X, String Y, int m, int n) {
		// Your code here
		t = new int[m + 1][n + 1];
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return m + n - LCS(X, Y, m, n);
	}
}


4. Print SCS

public class Solution {

	int t[][];

	public int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
	}

	public String shortestCommonSupersequence(String str1, String str2) {

		int n = str1.length();
		int m = str2.length();
		t = new int[n + 1][m + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				t[i][j] = -1;
			}
		}
		LCS(str1, str2, n, m);
		int i = n, j = m;
		String res = "";
		while (i > 0 || j > 0) {
			if (i > 0 && j > 0) {
				if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
					res = str1.charAt(i - 1) + res;
					i--;
					j--;
				} else {
					if (t[i - 1][j] > t[i][j - 1]) {
						res = str1.charAt(i - 1) + res;
						i--;
					} else {
						res = str2.charAt(j - 1) + res;
						j--;
					}
				}
			} else {
				while (i > 0) {
					res = str1.charAt(i - 1) + res;
					i--;
				}
				while (j > 0) {
					res = str2.charAt(j - 1) + res;
					j--;
				}

			}
		}

		return res;
	}
}


5. Minimum no. of insertion and deletion a-> b

a--> b
 
 LCS

First convert a to LCS by deleting the characters and after that insert to make LCS as b.

Example::
heap---> pea

LCS--> ea (deletes hp from heap)--> add p to ea-->(pea)

return m-LCS+n-LCS;==> m+n-2*LCS;

public class Solution {
	
	int t[][];

	public int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
	}

	public int minOperations(String str1, String str2) {
		// Your code goes here

		int n = str1.length(), m = str2.length();
		t = new int[n + 1][m + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				t[i][j] = -1;
			}
		}
		return n + m - 2 * LCS(str1, str2, n, m);

	}
}

6. Longest Repeating subsequence

public class Solution {

	int t[][];

	public int LRS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (n != m && X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + LRS(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(LRS(X, Y, n - 1, m), LRS(X, Y, n, m - 1));
	}

	public int LongestRepeatingSubsequence(String str) {

		int n = str.length();
		t = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return LRS(str, str, n, n);
	}
}


8. Subsequence pattern matching

public class Solution {

	int arr[][];

	public int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (arr[n][m] != -1)
			return arr[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return arr[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
		return arr[n][m] = Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
	}

	public boolean isSubsequence(String s, String t) {

		int n = s.length(), m = t.length();
		arr = new int[n + 1][m + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				arr[i][j] = -1;
			}
		}
		return n == LCS(s, t, n, m) ? true : false;

	}
}


10. Longest Palindromic Subsequence

LPS(a)==> LCS(a,reverse(a))

public class Solution {

	int t[][];

	public int longestPalinSubseq(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + longestPalinSubseq(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(longestPalinSubseq(X, Y, n - 1, m), longestPalinSubseq(X, Y, n, m - 1));
	}

	public int longestPalinSubseq(String S) {

		int n = S.length();
		StringBuilder builder = new StringBuilder();
		String rev = builder.append(S).reverse().toString();
		t = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return longestPalinSubseq(S, rev, n, n);
	}
}



13. Minimum no. of deletion in a string to make it a palindrome.

public class Solution {
	
	int t[][];

	int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
	}

	int minDeletions(String str, int n) {

		StringBuilder builder = new StringBuilder();
		String rev = builder.append(str).reverse().toString();
		t = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return n - LCS(str, rev, n, n);
	}
}


14. Minimum no. of insertion in a string to make it a palindrome.

public class Solution {

	int t[][];

	int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (t[n][m] != -1)
			return t[n][m];
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
		return t[n][m] = Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
	}

	int findMinInsertions(String S) {
		int n = S.length();
		StringBuilder builder = new StringBuilder();
		String rev = builder.append(S).reverse().toString();
		t = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				t[i][j] = -1;
			}
		}
		return n - LCS(S, rev, n, n);
	}
}
