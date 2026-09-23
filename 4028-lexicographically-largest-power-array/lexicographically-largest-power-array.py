class Solution:
       def largestPower(self, A: list[int]) -> list[int]:
        res = [0] * 15
        done = [0] * 15
        groups = [A]
        for i in range(15):
            groups2 = []
            for g in groups:
                if done[i]:
                    groups2.append(g)
                else:
                    g1 = [a for a in g if a & (1 << (14 - i))]
                    g2 = [a for a in g if not a & (1 << (14 - i))]
                    if g1:
                        res[i] += len(g1)
                        groups2.append(g1)
                    if g2:
                        done[i] = 1
                        groups2.append(g2)
            groups = groups2
        return res