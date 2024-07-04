**1. Binary Search**


Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.


```css
Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

Approach 1: Iterative


```java
public class Solution {

	public int search(int[] nums, int target) {
		int low = 0, high = nums.length - 1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] > target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return -1;

	}
}
```

Approach 2: Recursive  

```java
public class Solution {

	private int search(int[] nums, int target, int low, int high) {
		if (low > high) {
			return -1;
		}
		int mid = (low + high) / 2;
		if (nums[mid] == target) {
			return mid;

		}
		if (target > nums[mid]) {
			return search(nums, target, mid + 1, high);
		}
		return search(nums, target, low, mid - 1);
	}

	public int search(int[] nums, int target) {
		return search(nums, target, 0, nums.length - 1);
	}
}
```



```css
OverFlow Case:

mid = low + (high-low)/2
```


**2. Implement Lower Bound**

https://www.naukri.com/code360/problems/lower-bound_8165382

You are given an array 'arr' sorted in non-decreasing order and a number 'x'. You must return the index of the lower bound of 'x'.

Note:
1. For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' is not less than 'x'.If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.

2. Try to do this in O(log(n)).


```css
Sample Input 1:
6
1 2 2 3 3 5
0

Sample Output 1:
0

Explanation Of Sample Input 1 :
Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.

Sample Input 2:
6
1 2 2 3 3 5
2

Sample Output 2:
1

Sample Input 3:
6
1 2 2 3 3 5
7

Sample Output 3:
6
```

Solution


```java
public class Solution {

	public static int lowerBound(int[] arr, int n, int x) {

		int low = 0, high = n - 1;
		int ans = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] >= x) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return ans;
	}
}
```


**3. Implement Upper Bound**

https://www.naukri.com/code360/problems/implement-upper-bound_8165383

You are given a sorted array ‘arr’ containing ‘n’ integers and an integer ‘x’.Implement the ‘upper bound’ function to find the index of the upper bound of 'x' in the array.

Note:
1. The upper bound in a sorted array is the index of the first value that is greater than a given value.

2. If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.

3. Try to write a solution that runs in log(n) time complexity.


```css
Sample Input 1:
5 7
1 4 7 8 10

Sample Output 1:
3   

Explanation of sample output 1:
In the given test case, the lowest value greater than 7 is 8 and is present at index 3(0-indexed). 

Sample Input 2:
5 10
1 2 5 6 10   

Sample Output 2:
5

Sample Input 3:
7 5
1 5 5 7 7 9 10

Sample Output 3:
3
```

Solution


```java
public class Solution {
	
	public static int upperBound(int[] arr, int x, int n) {
		int low = 0, high = n - 1;
		int ans = n;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] > x) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return ans;
	}
}
```


**4. Search Insert Position**

https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813

You are given a sorted array 'arr' of distinct values and a target value 'm'. You need to search for the index of the target value in the array.

Note:

1. If the value is present in the array, return its index.

2. If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order.

3. The given array has distinct integers.

4. The given array may be empty.


```css
Sample Input 1:
4 9
1 2 4 7

Sample Output 1:
4

Explanation of Input 1:
The given array 'arr' is: [1, 2, 4, 7] and m = 9. We insert m = 9 in the array and get 'arr' as: [1, 2, 4, 7, 9]. The position of 9 is 4 (according to 0-based indexing).

Sample Input 2:
3 1
2 5 7

Sample Output 2
0

Explanation of Input 2:
The given array 'arr' is: [2, 5, 7] and m = 1. We insert m = 1 in the array and get 'arr' as: [1, 2, 5, 7]. The position of 1 is 0 (according to 0-based indexing)

Sample Input 3:
4 2
1 2 4 7

Sample Output 3:
1

Explanation of Input 3:
The given array 'arr' is: [1, 2, 4, 7] and m = 2. We already have 2 in 'A'. The position of 2 is 1 (according to 0-based indexing)
```


Solution


```java
public class Solution {
	
	public static int searchInsert(int[] arr, int m) {
		int low = 0, high = arr.length - 1;
		int ans = arr.length;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] >= m) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return ans;
	}
}
```


**5. Ceil The Floor**

https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

You're given a sorted array 'a' of 'n' integers and an integer 'x'.

Find the floor and ceiling of 'x' in 'a[0..n-1]'.

Note:

Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.

Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.


```css
Sample Input 1 :
6 8
3 4 4 7 8 10

Sample Output 1 :
8 8

Explanation of sample input 1 :
Since x = 8 is present in the array, it will be both floor and ceiling.

Sample Input 2 :
6 2
3 4 4 7 8 10

Sample Output 2 :
-1 3

Explanation of sample input 2 :
Since no number is less than or equal to x = 2 in the array, its floor does not exist. The ceiling will be 3.
```

Solution

```java
public class Solution {

	public static int[] getFloorAndCeil(int[] a, int n, int x) {

		int res[] = new int[2];
		res[0] = floor(a, x);
		res[1] = ceil(a, x);
		return res;

	}

	private static int ceil(int[] a, int x) {
		int low = 0, high = a.length - 1, ans = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (a[mid] >= x) {
				ans = a[mid];
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return ans;
	}

	private static int floor(int[] a, int x) {
		int low = 0, high = a.length - 1, ans = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (a[mid] <= x) {
				ans = a[mid];
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		return ans;
	}

}
```