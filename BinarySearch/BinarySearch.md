# Binary Search

## Overview

Binary search is an efficient algorithm for finding an element (or boundary) in a sorted array or for searching a monotonic function's solution. It repeatedly divides the search interval in half: if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half; otherwise narrow it to the upper half.

Precondition: the input sequence must be sorted (non-decreasing for most implementations). If this condition is not met, binary search results are undefined.

## Time and Space Complexity

- Time complexity: O(log n) comparisons in the worst case.
- Space complexity: O(1) for iterative implementations; O(log n) additional stack space for naive recursive implementations.

## Intuition

Imagine the sorted array as a list of numbered positions. You compare the target with the middle element. Each comparison halves the number of candidate positions. After k steps, you have reduced the candidate set to n / 2^k items. Stop when the target is found or the interval is empty.

A key invariant: at each step maintain a search interval [l, r] (inclusive or exclusive depending on implementation) that might still contain the target. The loop updates l or r while preserving the invariant.

## Common pitfalls

- Integer overflow when computing the mid index using (l + r) / 2. Use l + (r - l) / 2 instead.
- Off-by-one errors: be explicit whether r is inclusive or exclusive and keep the loop condition consistent.
- Using binary search on unsorted data.
- Wrong termination conditions when searching for boundaries (first/last occurrence).

## Safe iterative implementation (C++)

This example searches for value `x` in `arr` (vector<int>) and returns the index if found or -1 otherwise. It uses an inclusive [l, r] interval and avoids overflow.

```cpp
#include <vector>
using namespace std;

int binary_search_index(const vector<int>& arr, int x) {
    int l = 0;
    int r = (int)arr.size() - 1; // inclusive
    while (l <= r) { // interval is non-empty
        int mid = l + (r - l) / 2; // safe from overflow
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // not found
}
```

Notes:
- Use `l + (r - l) / 2` instead of `(l + r) / 2` to avoid overflow in languages where integer overflow can happen.

## Recursive implementation (C++)

```cpp
int binary_search_rec(const vector<int>& arr, int l, int r, int x) {
    if (l > r) return -1; // base: empty interval
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] < x) return binary_search_rec(arr, mid + 1, r, x);
    return binary_search_rec(arr, l, mid - 1, x);
}

int binary_search_index_rec(const vector<int>& arr, int x) {
    return binary_search_rec(arr, 0, (int)arr.size() - 1, x);
}
```

Recursive code is often simpler to read but uses O(log n) stack space.

## Finding the first (lower bound) / last (upper bound) occurrence

When the array contains duplicates, you may want the first index of a value or the last index.

First occurrence (lower bound behavior) — returns the smallest index i such that arr[i] >= x. If you need the exact first equal element, check arr[i] == x after.

```cpp
int lower_bound_index(const vector<int>& arr, int x) {
    int l = 0, r = (int)arr.size(); // notice r is exclusive
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l; // l in [0, n], first index where arr[l] >= x
}

int first_equal(const vector<int>& arr, int x) {
    int i = lower_bound_index(arr, x);
    if (i < (int)arr.size() && arr[i] == x) return i;
    return -1; // not found
}
```

Last occurrence (upper bound behavior) — returns the largest index i such that arr[i] <= x. Typically implemented via upper_bound and subtract 1.

```cpp
int upper_bound_index(const vector<int>& arr, int x) {
    int l = 0, r = (int)arr.size(); // r exclusive
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l; // first index where arr[l] > x
}

int last_equal(const vector<int>& arr, int x) {
    int ub = upper_bound_index(arr, x);
    int idx = ub - 1;
    if (idx >= 0 && arr[idx] == x) return idx;
    return -1;
}
```

## Using the C++ standard library

C++ provides std::lower_bound and std::upper_bound in <algorithm>, which implement the lower/upper bound semantics and are well-tested and optimized.

Example:

```cpp
#include <algorithm>
#include <vector>

// find first occurrence
auto it = std::lower_bound(arr.begin(), arr.end(), x);
if (it != arr.end() && *it == x) {
    int index = (int)distance(arr.begin(), it);
    // found at index
}
```

## Binary search on the answer (searching a monotonic predicate)

Binary search is useful when you have a monotonic predicate p(m) that is false for m < t and true for m >= t (or vice versa) and you want to find the boundary t.

Example: integer square root. Find largest integer r such that r*r <= n.

```cpp
long long integer_sqrt(long long n) {
    long long l = 0, r = n + 1; // r exclusive
    while (l + 1 < r) {
        long long mid = l + (r - l) / 2;
        if (mid * mid <= n) l = mid; // predicate true -> keep mid
        else r = mid;
    }
    return l;
}
```

Be careful of overflow in `mid * mid` for large n; use types that hold the product or compare using division: `mid <= n / mid` when mid > 0.

## Binary search on floating point values

For continuous domains, search until the interval length is below an epsilon. Example: find x in [lo, hi] such that f(x) is close to target.

```cpp
double binary_search_double(function<double(double)> f, double lo, double hi, double eps=1e-9) {
    while (hi - lo > eps) {
        double mid = lo + (hi - lo) / 2.0;
        if (f(mid) < 0) lo = mid; // depends on sign/monotonicity
        else hi = mid;
    }
    return (lo + hi) / 2.0;
}
```

Decide direction according to your predicate's monotonicity.

## Example usage and tests

Array: [1, 3, 3, 5, 7]
- Search 3 -> any valid index: 1 or 2 (binary_search_index returns one index)
- first_equal -> 1
- last_equal -> 2
- lower_bound for 4 -> index 3 (first >= 4)

Small test harness in C++:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1,3,3,5,7};
    std::cout << binary_search_index(a, 3) << "\n";
    std::cout << first_equal(a, 3) << "\n";
    std::cout << last_equal(a, 3) << "\n";
    std::cout << lower_bound_index(a, 4) << "\n";
    return 0;
}
```

Expected output (one possible correct output):
```
1
1
2
3
```

## Binary search in C

A simple iterative version in C for an array of ints:

```c
#include <stddef.h>

int binary_search_c(const int *arr, size_t n, int x) {
    size_t l = 0;
    if (n == 0) return -1;
    size_t r = n - 1;
    while (l <= r) {
        size_t mid = l + (r - l) / 2;
        if (arr[mid] == x) return (int)mid;
        if (arr[mid] < x) l = mid + 1;
        else {
            if (mid == 0) break; // avoid underflow
            r = mid - 1;
        }
    }
    return -1;
}
```

Note: use careful unsigned arithmetic to avoid underflow.

## Proving correctness (sketch)

Invariant approach:
- Maintain invariant: target is in [l, r] (inclusive) or not in array if l > r.
- Initialization: l = 0, r = n-1, so the target is either inside this interval or absent.
- Maintenance: each step compares arr[mid] with x and discards the half that cannot contain x while preserving the invariant.
- Termination: loop stops when l > r (empty interval) or when arr[mid] == x; thus algorithm terminates with correct answer.

## When not to use binary search

- On unsorted data.
- When data changes frequently and maintaining a sorted structure is expensive (use balanced BSTs or hash-based sets depending on needs).

## Quick reference checklist

- Ensure array is sorted.
- Decide whether intervals are inclusive or exclusive and be consistent.
- Use safe mid calculation to avoid overflow.
- For boundaries (first/last), use lower_bound/upper_bound patterns.
- Consider std::lower_bound/std::upper_bound in C++ to avoid reinventing the wheel.

---

If you want, I can also:
- Add more language examples (full C++ file with includes and a test runner),
- Add diagrams or ASCII visualizations, or
- Create unit tests (GoogleTest) or sample input/output files.
