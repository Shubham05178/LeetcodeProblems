from decimal import Decimal

class Solution:
    def combinations(self, s):
        if len(s) <= 1:
            return [int(s)]
        
        if s == '0'*(len(s)):
            return []
        
        if s[0] == '0':
            if s[-1] != '0':
                return [Decimal(s[0] + "." + s[1:])]
            else:
                return []
        
        temp = []
        temp.append(int(s))
        key = 0
        while key < len(s) -1:
            if s[-1] != '0':
                temp.append(Decimal(s[0:key+1] + "." + s[key+1:]))
            key += 1
        return temp
    
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s = s[1:-1]
        combs = []
        for i in range(0,len(s) -1):
            comb1 = self.combinations(s[0:i+1])
            comb2 = self.combinations(s[i+1:])
            for c1 in comb1:
                for c2 in comb2:
                    combs.append("("+str(c1)+", "+str(c2)+")")
        return combs