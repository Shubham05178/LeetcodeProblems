class Solution:
    def evaluate(self, s: str, d: list[list[str]]) -> str:
        return re.sub(r'\((\w+)\)',lambda m,d=dict(d):d.get(m[1],'?'),s)