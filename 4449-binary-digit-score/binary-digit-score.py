class Solution:
    def calculateScore(self, a: int, b: int) -> int:
        s1=bin(a)[2:].count('1')
        s2=bin(b)[2:].count('1')
        if s1>=s2:
            return s1*s2
        else:
            return s2//s1
        