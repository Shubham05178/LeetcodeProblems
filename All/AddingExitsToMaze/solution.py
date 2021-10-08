class Solution:
    def explore(self, graph, u, visited):
        visited[u] = 1
        for node in graph[u]:
            if visited[node] == 0:
                self.explore(graph, node, visited)

    def connectedComponents(self, n, edges):
        components = 0
        visited = [0] * n
        graph = {}
        for i in range(n):
            graph[i] = []
        for u, v in edges:
            graph[u-1].append(v-1)
            graph[v-1].append(u-1)
        for i in range(n):
            if visited[i] == 0:
                components += 1
                self.explore(graph, i, visited)
        return components


