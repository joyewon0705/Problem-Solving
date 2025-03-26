import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;

        Stack<Character> st = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            // 여는 괄호인 경우
            if (c == '(') st.push(c);
            // 닫는 괄호인 경우
            else {
                // 스택에 여는 괄호가 있는 경우, 꺼내기
                if (!st.empty() && st.peek() == '(') st.pop();
                // 그렇지 않는 경우, 오류
                else {
                    answer = false;
                    break;
                }
            }
        }
        
        // 스택이 비어있지 않은 경우, 오류
        if (!st.empty()) answer = false;

        return answer;
    }
}