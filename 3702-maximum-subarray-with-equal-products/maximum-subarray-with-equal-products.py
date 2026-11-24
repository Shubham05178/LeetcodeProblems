class Solution:
    def maxLength(self, nums: List[int]) -> int:
        from math import gcd
        res = 2
        prod_val = 1
        n = len(nums)
        start, end = 0, 0
        while end < n:
            while gcd(prod_val, nums[end]) > 1:
                prod_val //= nums[start]
                start += 1
            prod_val *= nums[end]
            res = max(res, end - start + 1)
            end += 1

        return res