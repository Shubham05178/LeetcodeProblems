class Solution:
    def maximizeSum(self, nums: list[int], k: int) -> int:
        arr=[]

        def cvt(val):
            l=list(str(val))
            return int("".join(sorted(l, reverse=True)))

        for i in range(len(nums)):
            arr.append([nums[i], cvt(nums[i]), cvt(nums[i])-nums[i]])

        arr.sort(key=lambda x:x[-1], reverse=True)

        total=0

        for i in range(k):
            total+=arr[i][1]

        for j in range(k,len(nums)):
            total+=arr[j][0]

        return total
            

        