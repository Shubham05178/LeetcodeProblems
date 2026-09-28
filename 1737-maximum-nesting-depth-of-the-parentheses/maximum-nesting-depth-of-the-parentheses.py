class Solution:
    def maxDepth(self, s: str) -> int:
        v=0
        m=0
        for i in s:
            if i=="(":
                v+=1
            elif i==")":
                v-=1
            m=max(m,v)
        return m