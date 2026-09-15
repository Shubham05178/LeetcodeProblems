class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)

        # palindrome[i][j] = True if s[i:j+1] is palindrome
        palindrome = [[False] * n for _ in range(n)]

        for i in range(n):
            palindrome[i][i] = True

        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1

                if s[i] == s[j]:
                    if length <= 2:
                        palindrome[i][j] = True
                    else:
                        palindrome[i][j] = palindrome[i + 1][j - 1]

        # dp[i] = maximum palindromes from i onwards
        dp = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            # Option 1: skip this character
            dp[i] = dp[i + 1]

            # Option 2: choose a palindrome starting at i
            for j in range(i + k - 1, n):
                if palindrome[i][j]:
                    dp[i] = max(dp[i], 1 + dp[j + 1])

        return dp[0]