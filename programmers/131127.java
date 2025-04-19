class Solution {
    
    final int N = 11;
    final int M = 101010;
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        int n = want.length;
        int m = discount.length;
        int [][][]a = new int[M][N][N];
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                if (discount[i].equals(want[k])) {
                    a[i][1][k] = 1;
                }
            }
            if (i == 0) continue;
            for (int j = 2; j < 11; j++) {
                for (int k = 0; k < n; k++) {
                    a[i][j][k] = a[i][1][k] + a[i - 1][j - 1][k];  
                }
            }
            boolean chk = true;
            for (int k = 0; k < n; k++) {
                if (number[k] != a[i][10][k]) {
                    chk = false;
                    break;
                }
            }
            if (chk) answer++;
        }
        
        return answer;
    }
}