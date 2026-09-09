class Solution:
    def countCommas(self, n: int) -> int:
        return sum(max((n-(10**i-1)),0) for i in range(3,16,3))
        