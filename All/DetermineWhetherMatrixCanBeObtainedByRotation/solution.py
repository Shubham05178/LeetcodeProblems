class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        for i in range(4):
            tempTarget = []
            for col, row in enumerate(mat):
                temp = []
                for j in range(len(row)):
                    temp.append(mat[len(row) - j - 1][col])
                tempTarget.append(temp)

            if tempTarget == target:
                return True
            else:
                mat = tempTarget
        return False
