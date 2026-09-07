class Solution:
    def distinctSubseqII(self, s: str) -> int:
        last=[-1]*26
        N=len(s)
        dp=[0]*(N+1)
        MOD=10**9+7
        dp[0]=1
        for i in range(N):
            x=ord(s[i])-ord('a')
            dp[i+1]=(dp[i]*2)%MOD
            if last[x]>=0:
                dp[i+1]-=dp[last[x]]
                dp[i+1]%=MOD
            last[x]=i
        dp[N]-=1
        if dp[N]<0:
            dp[N]+=MOD
        return dp[N]