class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        k=dict(knowledge)
        ans=""
        key=""
        keyt=False
        for i in s:
            if i=="(":
                keyt=True
            elif keyt==True and i!=")":
                key+=i
            elif i==")":
                ans+=k.get(key,"?")
                keyt=False
                key=""
            else:
                ans+=i
        return ans