import java.util.*;

class Solution {
    private static final int R = 4;
    private static final int[] DX = { -1, 1, 0, 0 };
    private static final int[] DY = { 0, 0, -1, 1 };
    
    private int n;
    private int answer = Integer.MAX_VALUE;
    
    public int solution(int[][] clockHands) {
        n = clockHands.length;
        
        dfs(0, 0, 0, clockHands);
        
        return answer;
    }
    
    private void dfs(int x, int y, int cnt, int[][] board) {
        if (y == n) {
            x++;
            y = 0;
        }
        
        if (x == 0) {
            // 첫 번째 행: 모든 경우 시도
            for (int r = 0; r < R; r++) {
                rotate(x, y, r, board);
                dfs(x, y + 1, cnt + r, board);
                rotate(x, y, (R - r) % R, board); // 복구
            }
        } else if (x == n) {
            // 종료 조건: 마지막 행이 모두 0인지 확인
            for (int j = 0; j < n; j++) {
                if (board[n - 1][j] > 0) return;
            }
            answer = Math.min(answer, cnt);
        } else {
            // 위 칸이 0이 되도록 회전
            int r = (R - board[x - 1][y]) % R;
            rotate(x, y, r, board);
            dfs(x, y + 1, cnt + r, board);
            rotate(x, y, (R - r) % R, board);  // 복구
        }
    }
    
    private void rotate(int x, int y, int r, int[][] board) {
        if (r == 0) return;
        
        rotateCell(x, y, r, board);
        for (int d = 0; d < R; d++) {
            int nx = x + DX[d];
            int ny = y + DY[d];
            
            if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
            
            rotateCell(nx, ny, r, board);
        }
    }
    
    private void rotateCell(int x, int y, int r, int[][] board) {
        board[x][y] = (board[x][y] + r) % R;
    }
}