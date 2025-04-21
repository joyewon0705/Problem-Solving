import java.util.*;

class Solution {
    
    int []dx = { -1, 1, 0, 0 };
    int []dy = { 0, 0, -1, 1 };
    
    public int[] solution(String[] grid) {
        int n = grid.length;
        int m = grid[0].length();
        boolean [][][]chk = new boolean[n][m][4];
        Vector<Integer> v = new Vector<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    if (chk[i][j][k]) continue; 
                    
                    int x = i, y = j, d = k, cnt = 0;
                    while (!chk[x][y][d]) {
                        chk[x][y][d] = true; 
                        
                        x += dx[d];
                        y += dy[d];
                        x = (x + n) % n;
                        y = (y + m) % m;
                        
                        if (grid[x].charAt(y) == 'L') {
                            if (d == 0) d = 2;
                            else if (d == 1) d = 3;
                            else if (d == 2) d = 1;
                            else d = 0;
                        }
                        else if (grid[x].charAt(y) == 'R') {
                            if (d == 0) d = 3;
                            else if (d == 1) d = 2;
                            else if (d == 2) d = 0;
                            else d = 1;
                        }
                        cnt++;
                    }
                    v.add(cnt);
                }
            }
        }
        
        Collections.sort(v);
        
        int[] answer = new int[v.size()];
        for (int i = 0; i < v.size(); i++) answer[i] = v.get(i);
        return answer;
    }
}