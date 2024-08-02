# Longest Common Subsequence

https://leetcode.com/problems/longest-common-subsequence/description/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


**Recursive Approach**

```java
public class Solution {

	int LCS(String X, String Y, int n, int m) {
		if (n == 0 || m == 0)
			return 0;
		if (X.charAt(n - 1) == Y.charAt(m - 1))
			return 1 + LCS(X, Y, n - 1, m - 1);
		return Math.max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));

	}
}
```


**Memoized Approach**

```java
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
```


**Top Down Approach**

```java
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
```

# Related Problems


**1. Longest Common Substring**

https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

Given two strings. The task is to find the length of the longest common substring.

```css
Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
```


```java
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
```


**2. Print LCS**

Approach 1: Tablular Approach

```java
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
```


Approach 2: Memoization Approach


```java
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
```


**3. Shortest Common SuperSequence**

https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.


```css
Input: X = abcd, Y = xycd
Output: 6

Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
```

```java
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
```


**4. Print SCS**

https://leetcode.com/problems/shortest-common-supersequence/description/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

```css
Input: str1 = "abac", str2 = "cab"
Output: "cabac"

Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
```


```java
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
```


**5. Minimum no. of insertion and deletion a-> b**

https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.


```css
Input: str1 = "heap", str2 = "pea"
Output: 3

Explanation: 2 deletions and 1 insertion.
p and h deleted from heap. Then, p is inserted at the beginning.
One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. Thus, p contributes one to the 
deletion_count and one to the insertion_count.

a--> b
 
 LCS

First convert a to LCS by deleting the characters and after that insert to make LCS as b.

Example::
heap---> pea

LCS--> ea (deletes hp from heap)--> add p to ea-->(pea)

return m-LCS+n-LCS;==> m+n-2*LCS;
```

```java
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
```

**6. Longest Repeating subsequence**

https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.


```css
Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
```


```java
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
```

**7. Length of Longest subsequence of a which is a substring of b.**

https://www.geeksforgeeks.org/problems/find-length-of-longest-subsequence4905/1

Given two string X and Y of length N and M respectively. The task is to find the length of the longest subsequence of string X which is a substring in sequence Y.

```css
Input:
N = 4, M = 8
X = "abcd"
Y = "bacdbdcd"
Output: 3

Explanation: "acd" is the longest subsequence
             from string X present as a
             substring in string Y.
```


```java
public class Solution {
	private int maxSubsequence(String X, String Y, int N, int M, int t[][]) {
		if (N == 0 || M == 0) {
			return 0;
		}
		if (t[N][M] != -1) {
			return t[N][M];
		}
		if (X.charAt(N - 1) == Y.charAt(M - 1)) {
			return t[N][M] = 1 + maxSubsequence(X, Y, N - 1, M - 1, t);
		}
		return t[N][M] = maxSubsequence(X, Y, N - 1, M, t);

	}

	int maxSubsequenceSubstring(String X, String Y, int N, int M) {
		int t[][] = new int[N + 1][M + 1];
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < N + 1; i++) {
			Arrays.fill(t[i], -1);
		}
		for (int i = 0; i <= M; i++) {
			max = Math.max(max, maxSubsequence(X, Y, N, i, t));
		}

		return max;
	}
}
```



**8. Subsequence pattern matching**

https://leetcode.com/problems/is-subsequence/description/

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


```css
Input: s = "abc", t = "ahbgdc"
Output: true
```


```java
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
```

**9. Count how many times a appear as subsequence in b**

https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

Return the total count modulo 1e9+7.

Input: s1 = geeksforgeeks, s2 = gks
Output: 4

Explaination: We can pick characters from s1 as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}.So total 4 subsequences of s1 that are equal to s2.


**10. Longest Palindromic Subsequence**

https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

Given a String, find the longest palindromic subsequence.

NOTE: Subsequence of a given sequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements


```css
Input: S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.

LPS(a)==> LCS(a,reverse(a))
```



```java
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
```


**11. Longest Palindromic substring**

https://leetcode.com/problems/longest-palindromic-substring/description/

Given a string s, return the longest palindromic substring in s.
 
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


**12. Count of Palindromic substring**

https://leetcode.com/problems/palindromic-substrings/description/

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


**13. Minimum no. of deletion in a string to make it a palindrome.**

https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

Given a string 'str' of size n. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum number of characters we need to remove.
Note: The order of characters should be maintained.

Example 1:

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".

```java
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
```


**14. Minimum no. of insertion in a string to make it a palindrome.**

https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1

Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd


Input: abcd
Output: 3

Explanation:
Here we can append 3 characters in the 
beginning,and the resultant string will 
be a palindrome ("dcbabcd").

```java
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
```

