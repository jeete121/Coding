# Pattern

```java
public class Solution {

	public int slideWindow(int arr[], int condition, int k) {
		int i = 0, j = 0, size = arr.length;
		int ans = 0;

		while (j < size) {
			// calculation

			if (condition < k)
				j++;

			else if (condition == k) {
				// ans<--- Calculation
				j++;
			}

			else if (condition > k) {
				while (condition > k) {
					// remove calculation for i
					i++;
				}
				j++;
			}
		}

		return ans;
	}

}
```


# All Sliding Window Question

https://leetcode.com/discuss/study-guide/3630462/Top-20-Sliding-Window-Problems-for-beginners

**Variable size::
**
**1. Largest/Smallest subarray of sum k.**

**2. Largest substring of k distinct character**

https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Solution::


```java
public class Solution {
	
	public int longestkSubstr(String s, int k) {
		int n = s.length();
		int i = 0, j = 0;
		int ans = 0;
		Map<Character, Integer> mp = new HashMap<>();
		while (j < n) {
			mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0) + 1);
			if (mp.size() < k)
				j++;
			else if (mp.size() == k) {
				ans = Math.max(ans, j - i + 1);
				j++;
			} else if (mp.size() > k) {
				while (i < n && mp.size() > k) {
					int x = mp.getOrDefault(s.charAt(i), 0);
					if (x == 1) {
						mp.remove(s.charAt(i));
						i++;
					} else {
						mp.put(s.charAt(i), x - 1);
						i++;
					}
				}
				j++;
			}
		}
		if (mp.size() < k)
			return -1;
		return ans;
	}
}
```


**3. Length of longest substring of no repeating character**

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Solution::

```java
public class Solution {
	
	public int lengthOfLongestSubstring(String s) {

		Map<Character, Integer> mp = new HashMap<>();
		int i = 0, j = 0;
		int ans = 0;
		int n = s.length();
		while (j < n) {
			int x = mp.getOrDefault(s.charAt(j), 0);
			if (x == 0) {
				mp.put(s.charAt(j), 1);
				if (j == n - 1)
					ans = Math.max(ans, j - i + 1);
				j++;
			} else {

				ans = Math.max(ans, j - i);
				while (i < n && s.charAt(i) != s.charAt(j)) {
					mp.remove(s.charAt(i));
					i++;
				}
				i++;
				j++;
			}

		}
		return ans;
	}
}
```

**4. Pick toy**

**5. Minimum Window subarray**

https://leetcode.com/problems/minimum-window-substring/description/

Solution:: 

```java
public class Solution {
	
	public String minWindow(String s, String t) {

		int m = s.length();
		int n = t.length();
		int i = 0, j = 0;
		Map<Character, Integer> mp = new HashMap<>();
		for (int l = 0; l < n; l++) {
			mp.put(t.charAt(l), mp.getOrDefault(t.charAt(l), 0) + 1);
		}
		int ans = Integer.MAX_VALUE;
		String res = "";
		int count = mp.size();
		while (j < m) {
			if (mp.containsKey(s.charAt(j))) {
				int x = mp.getOrDefault(s.charAt(j), 0);
				if (x == 1) {
					count--;
					mp.put(s.charAt(j), x - 1);
					if (count == 0) {
						while (i < m) {
							if (!mp.containsKey(s.charAt(i)))
								i++;
							else {
								int y = mp.getOrDefault(s.charAt(i), 0);
								// System.out.println("y = "+y);
								if (y == 0) {
									mp.put(s.charAt(i), y + 1);
									count++;
									if (j - i + 1 < ans) {
										ans = j - i + 1;
										res = s.substring(i, j + 1);
										// System.out.println(res);
									}
									i++;
									break;
								} else if (y < 0) {
									mp.put(s.charAt(i), y + 1);
									i++;
								}
							}
						}
					}
					j++;
				} else {
					mp.put(s.charAt(j), x - 1);
					j++;
				}
			} else
				j++;

		}
		return res;
	}
}
```

