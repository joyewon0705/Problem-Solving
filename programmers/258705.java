class Solution {
    private static final int MOD = 10007;
    
    public int solution(int n, int[] tops) {
        int[][] dp = new int[n][4];
        
        dp[0][0] = 1;                       // 정삼각형 타일로만 채우는 경우
        dp[0][1] = 1;                       // 2-8시 방향 마름모 타일을 놓는 경우
        dp[0][2] = 1;                       // 4-10시 방향 마름모 타일을 놓는 경우
        dp[0][3] = (tops[0] == 1) ? 1 : 0;  // 6-12시 방향 마름모 타일을 놓는 경우
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][2] = dp[i][0];
            dp[i][3] = (tops[i] == 1) ? dp[i][0] : 0; 
        }
        
        return (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3]) % MOD;
    }
}