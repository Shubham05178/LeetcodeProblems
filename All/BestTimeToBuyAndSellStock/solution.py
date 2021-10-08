class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        postfixMax = [0] * n
        pMax = prices[n-1]
        for i in range(n-2, -1, -1):
            pMax = max(pMax, prices[i+1])
            postfixMax[i] = pMax
        for i in range(n):
            prices[i] = postfixMax[i] - prices[i]

        maxProfit = max(prices)
        return maxProfit if maxProfit >= 0 else 0
