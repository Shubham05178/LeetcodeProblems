class Solution:
    def lastVisitedCell(self, grid: list[list[str]]) -> list[int]:
        dir={"R":(0,1),"L":(0,-1),"U":(-1,0),"D":(1,0)}
        vis=set()
        i,j=0,0
        n,m=len(grid),len(grid[0])
        while 0<=i <n and 0<=j <m and (i,j)  not in vis:
            last=[i,j]
            vis.add((i,j))
            x,y=dir[grid[i][j]]
            i+=x
            j+=y

        return last

        