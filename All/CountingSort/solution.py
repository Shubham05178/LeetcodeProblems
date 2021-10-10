class Solution:
    def countingSort(self, arr, maxVal):
        # print(arr)
        lookup = [0] * (maxVal + 1)
        for i in arr:
            lookup[i] += 1
        # print(lookup)
        for i in range(1, maxVal + 1):
            lookup[i] += lookup[i - 1]
        # print(lookup)
        sortedArr = [None] * len(arr)
        for i in range(len(arr) - 1, -1, -1):
            sortedArr[lookup[arr[i]] - 1] = arr[i]
            lookup[arr[i]] -= 1
        # print(sortedArr)
        return sortedArr
