class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        best = float('inf')
        for length in range(l, r + 1):
            s = 0
            for i in range(n):
                s += nums[i]
                if i >= length:
                    s -= nums[i - length]
                if i >= length - 1 and 0 < s < best:
                    best = s

        return -1 if best == float('inf') else best