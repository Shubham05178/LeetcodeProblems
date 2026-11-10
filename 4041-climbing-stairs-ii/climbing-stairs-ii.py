class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        n=len(costs)
        a,b,c=0,0,0
        for i in range(n):
            a,b,c=b,c,min(a+9,b+4,c+1)+costs[i]
        return c
        