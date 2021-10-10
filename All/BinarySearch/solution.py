class Solution:
    def binary_search(self, a, x):
        left, right = 0, len(a) - 1
        while left <= right:
            mid = (left + right) // 2
            if x > a[mid]:
                left = mid + 1
            elif x < a[mid]:
                right = mid - 1
            else:
                return mid
        return -1


print(Solution().binary_search([1, 5, 8, 12, 13], 8))
print(Solution().binary_search([1, 5, 8, 12, 13], 13))
