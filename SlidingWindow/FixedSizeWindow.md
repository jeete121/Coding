# Pattern

```java
public class Solution {

	public int slideWindow(int arr[], int k) {
		int i = 0, j = 0, size = arr.length;
		int ans = 0;
		while (j < size) {
			// calculation

			if (j - i + 1 < k) // windowSize==> (j-i+1)
				j++;
			else if (j - i + 1 == k) {
				// ans<--- Calculation
				// Calculation remove for ith index
				// Window size maintaind and slide window
				i++;
				j++;
			}
		}
		return ans;
	}
}
```


# All Problem Links for fixed size sliding window::


https://leetcode.com/discuss/interview-question/3100856/Fixed-Size-Sliding-Window-(Important-Questions-with-Solutions)


# Fixed Size::

**1. Maximum/Minimum Subarray of size k**

https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

NOTE*: A subarray is a contiguous part of any given array.


Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]

Output: 700

Explanation:
Arr3  + Arr4 =700,
which is maximum.

```java
public class Solution {

	long maximumSumSubarray(int K, List<Integer> arr, int N) {

		int i = 0, j = 0;
		int sum = 0;
		int mx = Integer.MIN_VALUE;
		while (j < N) {
			sum += arr.get(j);
			if (j - i + 1 < K)
				j++;
			else {
				mx = Math.max(mx, sum);
				sum -= arr.get(i);
				i++;
				j++;
			}
		}
		return mx;
	}
}
```

**2. First negative Number in every window of size k.**

https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.


Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2

Output : -8 0 -6 -6

Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6


```java
public class Compute {

	public long[] printFirstNegativeInteger(long A[], int N, int K) {
		int i = 0, j = 0;
		Queue<Long> q = new LinkedList<>();

		long ans[] = new long[N - K + 1];
		int l = 0;
		while (j < N) {
			if (A[j] < 0) {
				q.add(A[j]);
			}
			if (j - i + 1 < K) {
				j++;
			} else {
				if (!q.isEmpty()) {
					ans[l++] = q.peek();
					if (q.peek() == A[i]) {
						q.poll();
					}
					i++;
					j++;
				} else {
					ans[l++] = (long) 0;
					i++;
					j++;
				}
			}
		}

		return ans;
	}
}
```

**3. Count occurrences of anagrams.**

https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.


Input:
txt = forxxorfxdofr
pat = for

Output: 3

Explanation: for, orf and ofr appears
in the txt, hence answer is 3.


```java
public class Solution {

	int search(String pat, String txt) {

		int i = 0, j = 0, n = txt.length(), k = pat.length();
		int patFreq[] = new int[26];
		int txtFreq[] = new int[26];
		for (int l = 0; l < k; l++) {
			patFreq[pat.charAt(l) - 'a']++;
		}

		int cnt = 0;
		while (j < n) {
			txtFreq[txt.charAt(j) - 'a']++;
			if (j - i + 1 < k) {

				j++;
			} else {
				int flag = 0;
				for (int l = 0; l < 26; l++) {
					if (patFreq[l] != txtFreq[l]) {
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					cnt++;
				}
				txtFreq[txt.charAt(i) - 'a']--;
				i++;
				j++;
			}
		}
		return cnt;
	}
}
```

**4. Maximum of all subarray of size k.**

https://leetcode.com/problems/sliding-window-maximum/description/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

Output: [3,3,5,5,6,7]

Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


```java
import java.util.Deque;
import java.util.LinkedList;

public class Solution {
	public int[] maxSlidingWindow(int[] nums, int k) {

		Deque<Integer> dq = new LinkedList<>();

		int i = 0, j = 0, n = nums.length;

		int ans[] = new int[n - k + 1];
		int l = 0;
		while (j < n) {
			while (dq.size() > 0 && dq.peekLast() < nums[j]) {
				dq.pollLast();
			}
			dq.addLast(nums[j]);
			if (j - i + 1 < k) {
				j++;
			} else {
				ans[l++] = dq.peek();
				if (dq.peek() == nums[i]) {
					dq.poll();
				}
				i++;
				j++;
			}
		}
		return ans;
	}
}
```


**5. Max of minimum for every window size**

https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}

Output: 70 30 20 10 10 10 10 

Explanation: 

1. First element in output
indicates maximum of minimums of all
windows of size 1.

2. Minimums of windows of size 1 are {10},
 {20}, {30}, {50},{10}, {70} and {30}. 
 Maximum of these minimums is 70. 

3. Second element in output indicates
maximum of minimums of all windows of
size 2. 

4. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}.

5. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. 

6. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.

7. Maximum of these minimums is 20. 
Similarly other elements of output are
computed.

**6. Permutation in String**

https://leetcode.com/problems/permutation-in-string/description/

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"

Output: true

Explanation: s2 contains one permutation of s1 ("ba").


```java
public class Solution {

	public boolean checkInclusion(String s1, String s2) {

		int n = s1.length();
		int m = s2.length();
		int freq[] = new int[26];
		int freq1[] = new int[26];

		if (m < n) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			freq[s1.charAt(i) - 'a']++;
		}

		int i = 0, j = 0;
		while (j < m) {
			if (j - i + 1 < n) {
				freq1[s2.charAt(j) - 'a']++;
				j++;
			} else {
				int flag = 0;
				freq1[s2.charAt(j) - 'a']++;
				for (int k = 0; k < 26; k++) {
					if (freq[k] != freq1[k]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					return true;
				}
				freq1[s2.charAt(i) - 'a']--;
				i++;
				j++;
			}
		}

		return false;
	}

}
```