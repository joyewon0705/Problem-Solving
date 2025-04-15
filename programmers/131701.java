class Solution {
    
    final int N = 1010101;
    
    public int solution(int[] elements) {
        int answer = 0;
        int n = elements.length;
        boolean []chk = new boolean[N];
        int [][]dp = new int[n][n];
        
        for (int l = 0; l < n; l++) {
            for (int i = 0; i < n; i++) {
                int j = (i + l) % n;
                int k = (i + 1) % n;
                dp[i][j] = elements[i] + dp[k][j];
                if (!chk[dp[i][j]]) {
                    chk[dp[i][j]] = true;
                    answer++;
                }
            }
        }
        
        return answer;
    }
}