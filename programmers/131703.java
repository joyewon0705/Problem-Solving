import java.util.*;

class Solution {
    private static final int INF = Integer.MAX_VALUE;
    
    private int answer = INF;
    private int n; 
    private int m;
    private boolean[][] board;
    
    public int solution(int[][] beginning, int[][] target) {
        n = beginning.length;
        m = beginning[0].length;
        board = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = (beginning[i][j] == target[i][j]);
            }
        }
        
        dfsRow(0, 0);
        
        return answer == INF ? -1 : answer;
    }
    
    private void dfsRow(int r, int cnt) {
        if (r == n) {
            dfsColumn(0, cnt);
            return;
        }
        
        // 행을 뒤집지 않는 경우
        dfsRow(r + 1, cnt);
        
        // 행을 뒤집는 경우
        flipRow(r);
        dfsRow(r + 1, cnt + 1);
        flipRow(r);
    }
    
    private void dfsColumn(int c, int cnt) {
        if (c == m) {
            if (isPossible()) {
                answer = Math.min(answer, cnt);
            }
            return;
        }
        
        // 열을 뒤집지 않는 경우
        dfsColumn(c + 1, cnt);

        // 열을 뒤집는 경우
        flipColumn(c);
        dfsColumn(c + 1, cnt + 1);
        flipColumn(c);
    }
    
    private boolean isPossible() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void flipRow(int r) {
        for (int c = 0; c < m; c++) {
            board[r][c] = !board[r][c];
        }
    }
    
    private void flipColumn(int c) {
        for (int r = 0; r < n; r++) {
            board[r][c] = !board[r][c];
        }
    }
}