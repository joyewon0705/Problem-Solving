import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int cur : tangerine) {
            if (map.containsKey(cur)) map.put(cur, map.get(cur) + 1);
            else map.put(cur, 1);
        }
        
        Integer []values = map.values().toArray(new Integer[0]);
        Arrays.sort(values);
        
        int count = 0;
        for (int i = values.length - 1; i >= 0; i--) {
            if (count >= k) break;
            count += values[i];
            answer++;
        }
        
        return answer;
    }
}