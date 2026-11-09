class Solution:
    def longestCycle(self, edges: list[int]) -> int:
        n = len(edges)
        visited = [False] * n
        max_cycle = -1
        
        for i in range(n):
            if visited[i]:
                continue
                
            curr = i
            dist = {}
            curr_dist = 0
            while curr != -1 and not visited[curr]:
                visited[curr] = True
                dist[curr] = curr_dist
                curr = edges[curr]
                curr_dist += 1

            if curr != -1 and curr in dist:
                cycle_length = curr_dist - dist[curr]
                max_cycle = max(max_cycle, cycle_length)
                
        return max_cycle