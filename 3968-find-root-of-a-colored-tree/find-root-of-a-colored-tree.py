class Solution:
    def findColoredRoot(self, edges: list[list[int]], colors: str) -> int:
        nxt = {'R': 'B', 'B': 'W', 'W': 'R'}  # the color that comes after each color
        parent, children = [-1] * len(colors), [0] * len(colors)
        for u, v in edges:
            if nxt[colors[v]] == colors[u]:  
                u, v = v, u
            elif nxt[colors[u]] != colors[v]:
                return -1 
            if parent[v] != -1:
                return -1  
            parent[v] = u
            children[u] += 1
        root = parent.index(-1)  
        return root if children[root] <= 2 else -1  