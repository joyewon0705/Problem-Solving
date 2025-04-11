import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = { 0, 0 };
        int m = words.length;
        Vector<String> v = new Vector<>();
        
        v.add(words[0]);
        for (int i = 1; i < m; i++) {
            if (v.contains(words[i]) || 
                words[i - 1].charAt(words[i - 1].length() - 1) != words[i].charAt(0)) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                break;
            }
            v.add(words[i]);
        }

        return answer;
    }
}