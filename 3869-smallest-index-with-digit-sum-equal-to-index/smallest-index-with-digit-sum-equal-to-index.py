class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        def digitsum(n:int):
            s=0
            while n:
                s+=(n%10)
                n//=10
            return s
        for i,n in enumerate(nums):
            if i == digitsum(n):
                return i
        return -1