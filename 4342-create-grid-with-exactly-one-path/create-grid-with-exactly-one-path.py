class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        mat=["".join(["."]*n)]
        for i in range(m-1):
            arr=[]
            for j in range(n):
                if j!=n-1:
                    arr.append("#")
                else:
                    arr.append(".")
            mat.append("".join(arr))
        return mat