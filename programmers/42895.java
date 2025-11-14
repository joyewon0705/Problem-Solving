import java.util.*;

class Solution {
    public int solution(int N, int number) {
        if (N == number) return 1;
        
        List<Set<Integer>> dp = new ArrayList<>();
        for (int i = 0; i <= 8; i++) {
            dp.add(new HashSet<>());
        }
        
        dp.get(1).add(N);
        for (int i = 2; i <= 8; i++) {
            Set<Integer> cur = dp.get(i);
            
            cur.add(Integer.parseInt(String.valueOf(N).repeat(i)));
            for (int j = 1; j < i; j++) {
                for (int a : dp.get(j)) {
                    for (int b : dp.get(i - j)) {
                        cur.add(a + b);
                        cur.add(a - b);
                        cur.add(a * b);
                        if (b != 0) cur.add(a / b);
                    }
                }
            }
            
            if (cur.contains(number)) return i;
        }
        return -1;
    }
}