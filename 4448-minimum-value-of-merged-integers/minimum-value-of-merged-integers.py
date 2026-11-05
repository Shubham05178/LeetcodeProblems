class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        mini=float('inf')
        for i in range(0,len(nums),2):
            mini=min(mini,int(str(nums[i])+str(nums[i+1])))
        return mini

        