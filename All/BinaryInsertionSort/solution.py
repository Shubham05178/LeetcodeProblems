class Solution:
    def binarySearch(self, arr, num, l, r):
        if l == r:
            if arr[l] > num:
                return l
            return l + 1
        if l > r:
            return l
        mid = l + ((r - l) // 2)
        if arr[mid] > num:
            return self.binarySearch(arr, num, l, mid - 1)
        elif arr[mid] < num:
            return self.binarySearch(arr, num, mid + 1, r)
        else:
            return mid

    def binaryInsertionSort(self, arr):
        for i in range(1, len(arr)):
            item = arr[i]
            j = self.binarySearch(arr, item, 0, i - 1)
            arr = arr[:j] + [item] + arr[j:i] + arr[i+1:]
        return arr


print(Solution().binaryInsertionSort([5, 8, 12, 9, 21, 0, 3, -1, 3, 4, -2]))
