class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        self.ans=[]
        def generate(o,c,s):
            if o==n and c==n:
                self.ans.append(s)
                return
            
            if o>=c and o<n:
                t=s+"("
                generate(o+1,c,t)
            if c<o and c<n:
                t=s+")"
                generate(o,c+1,t)
        generate(0,0,"")
        return self.ans