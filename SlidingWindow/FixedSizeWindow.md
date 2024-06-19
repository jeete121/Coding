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


**5. Max of minimum for every window size k.**

**6. Permutation in String**

https://leetcode.com/problems/permutation-in-string/description/


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