
```java
public class Solution {
	
	int[] computeLPS(String pat, int m) {
		int lps[] = new int[m];
		int i = 1, len = 0;
		lps[0] = 0;
		while (i < m) {
			if (pat.charAt(i) == pat.charAt(len)) {
				len++;
				lps[i] = len;
				i++;

			} else {
				if (len != 0)
					len = lps[len - 1];
				else {
					lps[i] = 0;
					i++;
				}

			}
		}
		return lps;
	}

	ArrayList<Integer> search(String pat, String txt) {
		int n = txt.length(), m = pat.length();
		int lps[] = computeLPS(pat, m);
		int i = 0, j = 0;
		ArrayList<Integer> res = new ArrayList<>();
		while (i < n) {
			if (pat.charAt(j) == txt.charAt(i)) {
				i++;
				j++;
				if (j == m) {
					res.add(i - j + 1);
					j = lps[j - 1];
				}
			} else {
				if (j > 0)
					j = lps[j - 1];
				else
					i++;
			}
		}
		return res;

	}
}
```