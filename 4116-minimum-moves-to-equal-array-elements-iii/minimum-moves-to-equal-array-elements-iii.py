class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m=max(nums)
        ans=0
        for i in nums:
            ans+=(m-i)
        return ans
        