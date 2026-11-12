class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
    
        ans=1
        n=len(nums)
        if n ==0:
            return 0
        maxans=1
        for i in range(1,n):
            if nums[i-1]<nums[i]:
                ans+=1
                maxans=max(maxans,ans)
            else:
                ans=1
        ans=1
        for i in range(1,n):
            if nums[i-1]>nums[i]:
                ans+=1
                maxans=max(maxans,ans)
            else:
                ans=1
        return maxans 