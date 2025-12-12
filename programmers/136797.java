import java.util.*;

class Solution {
    private static final int INF = 1<<30;
    private static final int[][] POSITIONS = {
        { 4, 2 }, 
        { 1, 1 }, { 1, 2 }, { 1, 3 }, 
        { 2, 1 }, { 2, 2 }, { 2, 3 }, 
        { 3, 1 }, { 3, 2 }, { 3, 3 }
    };
    
    public int solution(String numbers) {
        int n = numbers.length();
        
        int[] digits = new int[n];
        for (int i = 0; i < n; i++) {
            digits[i] = numbers.charAt(i) - '0';
        }
        
        int[][][] dp = new int[n][10][10];
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < 10; l++) {
                for (int r = 0; r < 10; r++) {
                    dp[i][l][r] = INF;
                }
            }
        }
        
        dp[0][4][digits[0]] = getCost(6, digits[0]);
        dp[0][digits[0]][6] = getCost(4, digits[0]);
        for (int i = 1; i < n; i++) {
            int prev = digits[i - 1];
            int cur = digits[i];
            
            for (int l = 0; l < 10; l++) {
                int prevCost = dp[i - 1][l][prev];
                
                if (prevCost == INF) continue;
                
                if (l != cur) {
                    dp[i][l][cur] = Math.min(
                        dp[i][l][cur],
                        prevCost + getCost(prev, cur)
                    );
                }
                if (prev != cur) {
                    dp[i][cur][prev] = Math.min(
                        dp[i][cur][prev],
                        prevCost + getCost(l, cur)
                    );
                }
            }
            
            for (int r = 0; r < 10; r++) {
                int prevCost = dp[i - 1][prev][r];
                
                if (prevCost == INF) continue;
                
                if (prev != cur) {
                    dp[i][prev][cur] = Math.min(
                        dp[i][prev][cur],
                        prevCost + getCost(r, cur)
                    );
                }
                if (r != cur) {
                    dp[i][cur][r] = Math.min(
                        dp[i][cur][r],
                        prevCost + getCost(prev, cur)
                    );
                }
            }
        }
        
        int answer = INF;
        int lastDigit = digits[n - 1];
        for (int i = 0; i < 10; i++) {
            answer = Math.min(answer, dp[n - 1][i][lastDigit]);
            answer = Math.min(answer, dp[n - 1][lastDigit][i]);
        }
        return answer;
    }
    
    // 이동 가중치 계산
    private int getCost(int cur, int dest) {
        int dx = Math.abs(POSITIONS[cur][0] - POSITIONS[dest][0]);
        int dy = Math.abs(POSITIONS[cur][1] - POSITIONS[dest][1]);
        
        if (dx == 0 & dy == 0) {
            return 1;
        } 
        return 3 * Math.min(dx, dy) + 2 * Math.abs(dx - dy);
    }
}