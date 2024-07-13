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


**6. Find First and Last Position of Element in Sorted Array**

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

```css
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
```


Approach 1 : Using Upper Bound and Lower Bound

```java
public class Solution {
	private int upperBound(int[] nums, int target) {

		int n = nums.length;
		int low = 0, high = n - 1;

		int upperIndex = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] > target) {
				upperIndex = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return upperIndex;
	}

	private int lowerBound(int[] nums, int target) {

		int n = nums.length;
		int low = 0, high = n - 1;
		int lowerIndex = -1;

		while (low <= high) {

			int mid = low + (high - low) / 2;
			if (nums[mid] >= target) {
				lowerIndex = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return lowerIndex;

	}

	public int[] searchRange(int[] nums, int target) {

		int lowerB = lowerBound(nums, target);
		int upperB = upperBound(nums, target);

		if (lowerB == -1 || nums[lowerB] != target) {
			return new int[] { -1, -1 };
		}
		return new int[] { lowerB, upperB - 1 };

	}
}
```


Approach 2: Proper Binary Seach

```java
public class Solution {
	private int binarySearch(int[] nums, int target, boolean flag) {
		int n = nums.length;
		int low = 0, high = n - 1;

		int index = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == target) {
				index = mid;
				if (flag == true) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			} else if (nums[mid] > target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return index;
	}

	public int[] searchRange(int[] nums, int target) {
		int first = binarySearch(nums, target, true);
		if (first == nums.length) {
			return new int[] { -1, -1 };
		}
		int last = binarySearch(nums, target, false);
		
		return new int[] { first, last };
	}
}
```


**7. Number of occurrence**

https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456

You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.

Find the total number of occurrences of 'x' in the array/list.

```css
Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7 3
1 1 1 2 2 3 3


Sample Output 1:
2


Explanation For Sample Input 1:
In the given list, there are 2 occurrences of integer 3.


Sample Input 2:
 5 6
 1 2 4 4 5


Sample Output 2:
 0


Explanation For Sample Input 2:
In the given list, there are 0 occurrences of integer 6.
```

Expected time complexity: The expected time complexity is O(log 'n').

```java
public class Solution {

	private static int binarySeach(int arr[], int x, boolean flag) {

		int n = arr.length;
		int low = 0, high = n - 1;

		int index = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (arr[mid] == x) {
				index = mid;
				if (flag == true) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			} else if (arr[mid] > x) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return index;
	}

	public static int count(int arr[], int n, int x) {

		int first = binarySeach(arr, x, true);
		if (first == -1) {
			return 0;
		}
		int last = binarySeach(arr, x, false);
		return last - first + 1;

	}
}
```


**8. Search in Rotated Sorted Array**

https://leetcode.com/problems/search-in-rotated-sorted-array/description/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


```css
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
```


Identity the Sorted Half

```java
public class Solution {
	public int search(int[] nums, int target) {

		int n = nums.length;
		int low = 0, high = n - 1;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			// left half sorted
			else if (nums[low] <= nums[mid]) {
				// if element lies in the left sorted half
				if (nums[low] <= target && nums[mid] >= target) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			// right half sorted
			else {
				// if element lies in the right sorted half
				if (nums[mid] <= target && nums[high] >= target) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
		}
		return -1;

	}
}
```


**9. Search in Rotated Sorted Array II**

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.


```css
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```


Solution

```java
public class Solution {
	public boolean search(int[] nums, int target) {

		int n = nums.length;
		int low = 0, high = n - 1;

		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (nums[mid] == target) {
				return true;
			}

			// if all the three pointers are equal
			if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
				low++;
				high--;
				continue;
			}
			// left half sorted
			if (nums[low] <= nums[mid]) {
				if (nums[low] <= target && nums[mid] >= target) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			// right half sorted
			else {
				if (nums[mid] <= target && nums[high] >= target) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
		}

		return false;

	}
}
```


**10. Find Minimum in Rotated Sorted Array**

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.

[0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

```css
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
```

Solution


```java
public class Solution {
	public int findMin(int[] nums) {

		int n = nums.length;
		int low = 0, high = n - 1;

		int ans = Integer.MAX_VALUE;
		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (nums[mid] >= nums[low]) {
				ans = Math.min(ans, nums[low]);
				low = mid + 1;
			} else {
				ans = Math.min(ans, nums[mid]);
				high = mid - 1;
			}
		}
		return ans;
	}
}
```


Optimized Approach


```java
public class Solution {
	public int findMin(int[] nums) {

		int n = nums.length;
		int low = 0, high = n - 1;

		int ans = Integer.MAX_VALUE;
		while (low <= high) {
			int mid = low + (high - low) / 2;

			// if search space is already sorted
			// then always nums[low] will be the minimum
			// in the search space
			if (nums[low] <= nums[high]) {
				ans = Math.min(ans, nums[low]);
				break;
			}
			if (nums[mid] >= nums[low]) {
				ans = Math.min(ans, nums[low]);
				low = mid + 1;
			} else {
				ans = Math.min(ans, nums[mid]);
				high = mid - 1;
			}
		}
		return ans;
	}
}
```


**11. Find out how many times array has been rotated(Rotation)**

https://www.naukri.com/code360/problems/rotation_7449070

You are given an array 'arr' having 'n' distinct integers sorted in ascending order. The array is right rotated 'r' times

Find the minimum value of 'r'.

Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, for all 'i' from 0 to ‘n-1'.

```css
Example:
Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]

Output: 3 

Explanation:
If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. Thus 'r' = 3.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
2 3 4 1


Sample Output 1:
3   


Explanation of sample output 1:
If we right rotate the array {1, 2, 3, 4} by '3' times then we will get {2, 3, 4, 1}. Thus 'r' = 3.


Sample Input 2:
3
1 2 3


Sample Output 2:
0


Explanation of sample output 2:
If we right rotate the array {1, 2, 3} by '0' time then we will get {1, 2, 3}. Thus 'r' = 0.
```

Expected time complexity: Can you solve this in O(logn) time complexity?


```java
public class Solution {
	public static int findKRotation(int[] arr) {
		int n = arr.length;

		int low = 0, high = n - 1;
		int minValue = Integer.MAX_VALUE, minIndex = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (arr[low] <= arr[mid]) {
				if (arr[low] < minValue) {
					minValue = arr[low];
					minIndex = low;
				}
				low = mid + 1;

			} else {
				if (arr[mid] < minValue) {
					minValue = arr[mid];
					minIndex = mid;
				}
				high = mid - 1;
			}
		}
		return minIndex;
	}
}
```


**12. Single Element in a Sorted Array**

https://leetcode.com/problems/single-element-in-a-sorted-array/description/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

```css
Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
```


```java
public class Solution {
	public int singleNonDuplicate(int[] nums) {

		int n = nums.length;
		if (n == 1) {
			return nums[0];
		}
		if (nums[0] != nums[1]) {
			return nums[0];
		}
		if (nums[n - 1] != nums[n - 2]) {
			return nums[n - 1];
		}
		int low = 1, high = n - 2;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) {
				return nums[mid];
			} else if (mid % 2 == 1) {
				if (nums[mid] == nums[mid - 1]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			} else {
				if (nums[mid] == nums[mid + 1]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
		}

		return -1;

	}
}
```


**13. Find Peak Element**

https://leetcode.com/problems/find-peak-element/description/

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

```css
Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```


Solution


```java
public class Solution {
	public int findPeakElement(int[] nums) {

		int n = nums.length;
		if (n == 1) {
			return 0;
		}
		if (nums[0] > nums[1]) {
			return 0;
		}
		if (nums[n - 1] > nums[n - 2]) {
			return n - 1;
		}
		int low = 1, high = n - 2;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
				return mid;
			}
			if (nums[mid] < nums[mid - 1]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return -1;
	}
}
```



**14. Sqrt(x)**

https://leetcode.com/problems/sqrtx/description/

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


```css
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

Solution

```java
public class Solution {
    public int mySqrt(int x) {

        int low = 0, high = x;

        if(x == 0 || x == 1){
            return x;
        }
        int ans = x;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid <= x/mid){
              ans = mid;
              low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }
        return ans;
        
    }
}
```

**15. Find Nth Root Of M**

https://www.naukri.com/code360/problems/nth-root-of-m_1062679

You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.

Note:

'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.


```css
Example:
Input: ‘n’ = 3, ‘m’ = 27

Output: 3

Explanation: 
3rd Root of 27 is 3, as (3)^3 equals 27.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3 27

Sample Output 1:
3

Explanation For Sample Input 1:
3rd Root of 27 is 3, as (3)^3 equals 27.

Sample Input 2:
4 69

Sample Output 2:
-1

Explanation For Sample Input 2:
4th Root of 69 is not an integer, hence -1.

Expected Time Complexity:
Try to do this in O(log(n+m)).
```


Solution:


```java
public class Solution {

	private static int func(int mid, int n, int m) {

		long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * mid;
			if (ans > m) {
				return 2;
			}
		}
		if (ans == m) {
			return 1;
		}
		return 0;

	}

	public static int NthRoot(int n, int m) {

		int low = 1, high = m;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			int number = func(mid, n, m);
			if (number == 1) {
				return mid;
			} else if (number == 2) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return -1;
	}
}
```


**16. Koko Eating Bananas**

https://www.naukri.com/code360/problems/minimum-rate-to-eat-bananas_7449064

A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.


```css
Example:

Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

Output: 3

Explanation: If ‘m’ = 3, then 
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 2 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 3 hour.
Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
7 15 6 3
8

Sample Output 1:
5


Explanation Of Sample Input 1:
Input: ‘n’ = 4, ‘a’ = [7, 15, 6, 3], ‘h’ = 8

Output: 5

Explanation: If ‘m’ = 5, then 
The time taken to empty the 1st pile is 2 hour.
The time taken to empty the 2nd pile is 3 hour.
The time taken to empty the 3rd pile is 2 hour.
The time taken to empty the 4th pile is 1 hour.
Therefore a total of 8 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 8 hours.


Sample Input 2:
5
25 12 8 14 19
5


Sample Output 2:
25


Explanation Of Sample Input 2:
Input: ‘n’ = 5, ‘a’ = [25,12,8,14,19], ‘h’ = 5

Output: 25

Explanation: If ‘m’ = 25, 
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 1 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 1 hour.
The time taken to empty the 5th pile is 1 hour.
Therefore a total of 5 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 5 hours.


Expected Time Complexity:
Try to solve the problem in O(log n).
```


Solution


```java
public class Solution {

	private static int minimumRate(int v[], int m) {
		int total = 0;
		for (int i = 0; i < v.length; i++) {
			total += Math.ceil((double) (v[i]) / (double) (m));

		}
		return total;
	}

	public static int minimumRateToEatBananas(int[] v, int h) {
		int maxElement = -1;
		for (int i = 0; i < v.length; i++) {
			if (maxElement < v[i]) {
				maxElement = v[i];
			}
		}
		int low = 1, high = maxElement;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int total = minimumRate(v, mid);
			if (total <= h) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}

		}

		return low;
	}
}
```


**17. Rose Garden**

https://www.naukri.com/code360/problems/rose-garden_2248080

You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.

You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.

Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.



```css
Example :
Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2

Output: 3. 

Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
9
1 2 1 2 7 2 2 3 1
3 2
Sample Output 1 :
3
Explanation For Sample Input 1 :
We will return 3, because:
All the roses with 'arr[i]' less than equal to 3 have already bloomed after 3 days, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.

Sample Input 2 :
4
1 1 1 1
1 1
Sample Output 2 :
1
```


Solution:

```java
public class Solution {

	private static int func(int arr[], int m, int k) {

		int cnt = 0;
		int i = 0, n = arr.length;
		int total = 0;
		while (i < n) {
			if (arr[i] <= m) {
				while (i < n && arr[i] <= m) {
					cnt++;
					i++;
				}
				total += cnt / k;
			} else {
				i++;
			}
			cnt = 0;
		}
		return total;

	}

	public static int roseGarden(int[] arr, int r, int b) {

		int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;

		for (int i = 0; i < arr.length; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		int low = min, high = max;
		int ans = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int count = func(arr, mid, r);
			if (count >= b) {
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


**18. Smallest divisor**

https://www.naukri.com/code360/problems/smallest-divisor-with-the-given-limit_1755882

You are given an array of integers 'arr' and an integer 'limit'.

Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.

Note:
Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example, 7/3 = 3.


```css
Sample Input 1 :
5
1 2 3 4 5
8  
Sample Output 1 :
3
Explanation for Sample Input 1 :
We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor, and the sum is 7(1 + 1 + 1 + 2 + 2) if we choose 3 as a divisor, which is less than the 'limit'.
Hence we return 3.
Sample Input 2 :
4
8 4 2 3 
10

Sample Output 2 :
2

Explanation for Sample Input 2:
We can get a sum of 17(8 + 4 + 2 + 3) if we choose 1 as a divisor. 
The sum is 9(4 + 2 + 1 + 2) if we choose 2 as a divisor, which is less than the 'limit'.
Hence, we return 2.

Sample Input 3:
5
2 3 5 7 11
11
Sample Output 3 :
3
```

```java
public class Solution {

	private static int func(int arr[], int m) {
		int total = 0;

		for (int i = 0; i < arr.length; i++) {
			total += Math.ceil((double) (arr[i]) / (double) (m));
		}
		return total;

	}

	public static int smallestDivisor(int arr[], int limit) {

		int n = arr.length;
		int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		int low = min, high = max;

		int ans = low;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int count = func(arr, mid);

			if (count <= limit) {
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