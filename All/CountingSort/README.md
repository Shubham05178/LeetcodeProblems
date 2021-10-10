# Counting Sort

- Counting Sort is a linear sorting algorithm.
- Time complexity of Counting Sort is O(n+k), where n is the size of the sorted array and k is the range of key values.
- It is not an in-place sorting algorithm as it requires extra additional space O(k).
- Counting Sort is stable sort as relative order of elements with equal values is maintained.
- Counting Sort is inefficient if the range of key value (k) is very large. If the input array is already sorted then also it will require an additional array to store the sorted elements and will process it completely.
- Counting Sort has a disadvantage that it can only sort discrete values like integer, as frequency range cannot be constructed for other values.

### Example 1
```sh
Input: arr = [4, 7, 2, 5, 5, 1, 7, 8, 3, 5, 3, 2, 1, 3, 3, 9, 3, 7, 8, 4], maxVal = 9
Output: [1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 7, 7, 7, 8, 8, 9]
```
