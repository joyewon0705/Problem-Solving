import java.util.*;

class Solution {
    
    public int solution(String s) {
        int answer = 1;

        Stack<Character> st = new Stack();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!st.isEmpty() && st.peek() == c) st.pop();
            else st.push(c);
        }
        if (st.size() > 0) answer = 0;

        return answer;
    }
}