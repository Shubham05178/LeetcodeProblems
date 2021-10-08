class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        lookup = [[m*n for _ in range(n)] for _ in range(m)]
        # Either moving up or left
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 0:
                    lookup[row][col] = 0
                else:
                    if row > 0:
                        lookup[row][col] = min(lookup[row][col], 1 + lookup[row - 1][col])
                    if col > 0:
                        lookup[row][col] = min(lookup[row][col], 1 + lookup[row][col - 1])
        # Either moving down or right
        for row in range(m - 1, -1, -1):
            for col in range(n - 1, -1, -1):
                if row < m - 1:
                    lookup[row][col] = min(lookup[row][col], 1 + lookup[row + 1][col])
                if col < n - 1:
                    lookup[row][col] = min(lookup[row][col], 1 + lookup[row][col + 1])
        return lookup
