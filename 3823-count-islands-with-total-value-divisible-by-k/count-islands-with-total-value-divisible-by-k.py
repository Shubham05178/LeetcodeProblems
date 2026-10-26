class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        n,m=len(grid),len(grid[0])
        vis=[[0 for _ in range(m)] for _ in range(n)]
        dir=[(0,1),(0,-1),(1,0),(-1,0)]
        def dfs(i,j):
            vis[i][j]=1
            curr_sum=grid[i][j]

            for x,y in dir:
                nx=x+i
                ny=y+j
                if 0<=nx<n and 0<=ny<m and vis[nx][ny]==0 and grid[nx][ny]!=0:
                    curr_sum+=dfs(nx,ny)
            return curr_sum
        c=0
        for i in range(n):
            for j in range(m):
                if vis[i][j]==0 and grid[i][j]!=0:
                    if dfs(i,j)%k==0:
                        c+=1
        return c

        