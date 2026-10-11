class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        s=0
        n=len(nums)
        for i,el in enumerate(nums):
            if n%(i+1)==0:
                s+=(nums[i]*nums[i])
        return s
        