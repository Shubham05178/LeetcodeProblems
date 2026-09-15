class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n,m=len(matrix),len(matrix[0])
        dir=[(0,1),(0,-1),(1,0),(-1,0)]
        @cache
        def dp(i,j):
            result=1
            for x, y in dir:
                nx=i+x
                ny=j+y
                if 0<=nx<n and 0<=ny<m and matrix[nx][ny]>matrix[i][j]:
                    result=max(result,1+dp(nx,ny))
            return result
        ans=0
        for i in range(n):
            for j in range(m):
                ans=max(ans,dp(i,j))
        return ans