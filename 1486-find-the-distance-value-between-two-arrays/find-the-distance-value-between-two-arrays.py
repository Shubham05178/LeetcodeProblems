class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        c=0
        for i in range(len(arr1)):
            flag=False
            for j in range(len(arr2)):
                if not flag and abs(arr1[i]-arr2[j])<=d:
                    flag=True
                    break
            if not flag:
                c+=1
        return c
        