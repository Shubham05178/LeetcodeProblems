class Solution:
    def checkString(self, s: str) -> bool:
        cha=True
        for ch in s:
            if ch=='a' and cha==False:
                return False
            elif ch=='b':
                cha=False
        return True