class Solution {
    
    final long MOD = 1234567;
    
    public long solution(int n) {
        long answer = 0;
        
        long [][]dp = new long[n + 1][2];
        
        dp[0][0] = dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
        }
        answer = (dp[n][0] + dp[n][1]) % MOD;
        
        return answer;
    }
}