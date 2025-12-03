import java.util.*;

class Solution {
    private static final long INF = 1L << 60;
    
    public long solution(int[] sequence) {
        long answer = -INF;
        
        int sign = 1;
        long p = -INF;
        long m = -INF;
        for (int i : sequence) {
            p = Math.max(p + sign * i, sign * i);
            sign *= -1;
            m = Math.max(m + sign * i, sign * i);
            answer = Math.max(answer, Math.max(p, m));
        }
        
        return answer;
    }
}