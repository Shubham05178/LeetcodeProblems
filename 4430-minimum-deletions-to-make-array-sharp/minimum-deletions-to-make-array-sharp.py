class Solution:
    def minDeletions(self, nums: list[int]) -> int:
        j=0
        n=len(nums)
        for i in range(n-1):
            if nums[i]^nums[i+1]==0:
                j+=1
        return j
        