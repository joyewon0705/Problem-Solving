import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            Stack<Integer> st = new Stack<>();
            for (int j = 0; j < n; j++) {
                int ni = (i + j) % n;
                int cur = c2i(s.charAt(ni));
                if (!st.isEmpty() && st.peek() - cur == 3) st.pop();
                else st.push(cur);
            }
            if (st.isEmpty()) answer++;
        }
        
        return answer;
    }
    
    int c2i(char ch) {
        switch (ch) {
            case '(': return 6;
            case '[': return 5;
            case '{': return 4;
            case ')': return 3;
            case ']': return 2;
            case '}': return 1;
        }
        return 0;
    }
}