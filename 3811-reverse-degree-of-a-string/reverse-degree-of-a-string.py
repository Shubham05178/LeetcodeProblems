class Solution:
    def reverseDegree(self, s: str) -> int:
        p=0
        for i,ch in enumerate(s):
            x=(ord('z'))-ord(ch)+1
            p+=(x*(i+1))
        return p
        