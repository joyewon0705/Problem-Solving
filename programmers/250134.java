import java.util.*;

class Solution {
    private static final int INF = 1<<30;
    private static final int[] dx = { -1, 1, 0, 0 };
    private static final int[] dy = { 0, 0, -1, 1 };
    
    private int answer = INF;
    private int n, m;
    private boolean[][][] visited;
    private int[][] destination = new int[2][2];
    
    public int solution(int[][] maze) {
        n = maze.length;
        m = maze[0].length;
        visited = new boolean[2][n][m];
        
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                switch(maze[i][j]) {
                    case 1 -> { // 빨간 수레 시작 칸
                        x1 = i; 
                        y1 = j;
                        visited[0][i][j] = true; 
                    }
                    case 2 -> { // 파란 수레 시작 칸
                        x2 = i; 
                        y2 = j;
                        visited[1][i][j] = true; 
                    }
                    case 3 -> { // 빨간 수레 도착 칸
                        destination[0][0] = i; 
                        destination[0][1] = j; 
                    }
                    case 4 -> { // 파란 수레 도착 칸
                        destination[1][0] = i; 
                        destination[1][1] = j; 
                    }
                    case 5 -> { // 벽
                        visited[0][i][j] = true;
                        visited[1][i][j] = true; 
                    }
                }
            }
        }
        
        dfs(0, x1, y1, x2, y2);
        
        return (answer >= INF) ? 0 : answer;
    }
    
    private void dfs(int turns, int x1, int y1, int x2, int y2) {
        if (isArrived(0, x1, y1) && isArrived(1, x2, y2)) {
            answer = Math.min(answer, turns);
            return;
        }
        
        // 빨간 수레 이동
        for (int d1 = 0; d1 < 4; d1++) {
            int nx1 = x1;
            int ny1 = y1;
            
            // 빨간 수레가 도착 칸이 아니면 이동 시도
            if (!isArrived(0, x1, y1)) {
                nx1 += dx[d1];
                ny1 += dy[d1];
                
                if (!isValid(0, nx1, ny1)) {
                    continue;
                }
            }
            
            // 파란 수레 이동
            for (int d2 = 0; d2 < 4; d2++) {
                int nx2 = x2;
                int ny2 = y2;
                
                // 파란 수레가 도착 칸이 아니면 이동 시도
                if (!isArrived(1, x2, y2)) {
                    nx2 += dx[d2];
                    ny2 += dy[d2];
                    
                    if (!isValid(1, nx2, ny2)) {
                        continue;
                    }
                }
                
                if ((nx1 == nx2 && ny1 == ny2)  // 같은 칸으로 이동
                   || (x1 == nx2 && y1 == ny2 && x2 == nx1 && y2 == ny1)) { // 자리 교환
                    continue;
                }
                
                visited[0][nx1][ny1] = true;
                visited[1][nx2][ny2] = true;
                
                dfs(turns + 1, nx1, ny1, nx2, ny2);
                
                visited[0][nx1][ny1] = false;
                visited[1][nx2][ny2] = false;
                
                if (nx2 == x2 && ny2 == y2) break;
            }
            if (nx1 == x1 && ny1 == y1) break;
        }
    }
    
    private boolean isArrived(int color, int x, int y) {
        switch(color) {
            case 0 -> {
                return x == destination[0][0] && y == destination[0][1];
            }
            case 1 -> {
                return x == destination[1][0] && y == destination[1][1];
            }
            default -> {
                return false;
            }
        }
    }
    
    private boolean isValid(int color, int x, int y) {
        return !(x < 0 || n <= x || y < 0 || m <= y || visited[color][x][y]);
    }
}