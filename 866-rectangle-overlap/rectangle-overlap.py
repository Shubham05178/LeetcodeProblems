class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1=rec1[0]
        x2=rec1[2]
        x3=rec2[0]
        x4=rec2[2]
        y1=rec1[1]
        y2=rec1[3]
        y3=rec2[1]
        y4=rec2[3]
        return x1<x4 and y1<y4 and x2>x3 and y2>y3
        
        