class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n=len(nums)
        min_=[float('inf')]*n
        min_[-1]=nums[-1]
        for i in range(n-2,-1,-1):
            min_[i]=min(min_[i+1],nums[i])
        m=nums[0]
        for i in range(n):
            m=max(m,nums[i])
            if m-min_[i]<=k:
                return i
        return -1
