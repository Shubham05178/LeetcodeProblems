class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        a=[]
        nums.sort()
        j=0
        for i,element in enumerate(nums):
            if element==target:
                a.append(i)
        return a