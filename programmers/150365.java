import java.util.*;

class Solution {
    private static final int[] DX = { 1, 0, 0, -1 };
    private static final int[] DY = { 0, -1, 1, 0 };
    private static final char[] DIR = { 'd', 'l', 'r', 'u' };
    
    private boolean[][][] visited;
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        visited = new boolean[n + 1][m + 1][k + 1];
        
        Queue<State> q = new ArrayDeque<>();
        q.offer(new State(x, y, 0, ""));
        
        while (!q.isEmpty()) {
            State cur = q.poll();
            
            // 방문 검사
            if (visited[cur.x][cur.y][cur.count]) continue;
            visited[cur.x][cur.y][cur.count] = true;
            
            // k번 이동한 경우
            if (cur.count == k) {
                if (cur.x == r && cur.y == c) {
                    return cur.path;
                }
                continue;
            }
            
            // 4방향 BFS
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + DX[d];
                int ny = cur.y + DY[d];
                
                if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
                
                String npath = cur.path + DIR[d];
                q.offer(new State(nx, ny, cur.count + 1, npath));
            }
        }
        
        return "impossible";
    }
    
    private static class State {
        final int x;
        final int y;
        final int count;
        String path;
        
        State(int x, int y, int count, String path) {
            this.x = x;
            this.y = y;
            this.count = count;
            this.path = path;
        }
    }
}