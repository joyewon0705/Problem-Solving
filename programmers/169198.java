class Solution {
    
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        int k = balls.length;
        int []answer = new int[k];
        
        for (int i = 0; i < k; i++) {
            int x = balls[i][0];
            int y = balls[i][1];
            
            int dist = Integer.MAX_VALUE;
            if (startX != x || startY < y) {
                dist = Math.min(dist, square(startX - x) + square(startY + y));
            }
            if (startX != x || startY > y) {
                dist = Math.min(dist, square(startX - x) + square(2 * n - startY - y));
            }
            if (startY != y || startX < x) {
                dist = Math.min(dist, square(startX + x) + square(startY - y));
            }
            if (startY != y || startX > x) {
                dist = Math.min(dist, square(2 * m - startX - x) + square(startY - y));
            }
            answer[i] = dist;
        }
        
        return answer;
    }
    
    public int square(int x) {
        return x * x;
    }
}