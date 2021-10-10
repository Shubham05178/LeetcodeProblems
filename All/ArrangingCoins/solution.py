class Solution:
    def getTotalCoinsTillRow(self, row):
        return row * (row + 1) // 2

    def arrangeCoins(self, n: int) -> int:
        if n == 1:
            return 1
        """
            If there are n coins then there could be max of ceil(n/2) rows that can be fully filled as ith row needs i coins so (n/2)th row would need n/2 coins that means we can't have (n/2)+1 row as all the coins would be exhausted to fill the previous rows.
            Now we can use binary search from 1 - ceil(n/2) to check what would be the last row that get's completely filled by available coins.
            Also notice that to fill n rows completely, we need n*(n+1)/2 coins (Simple Arithmetic Progression AP)
        """
        start = 1
        end = n // 2 + 1
        while start <= end:
            mid = start + ((end - start) // 2)
            coins = self.getTotalCoinsTillRow(mid)
            if coins == n:
                return mid
            elif coins < n:
                start = mid + 1
            else:
                end = mid - 1
        return end
