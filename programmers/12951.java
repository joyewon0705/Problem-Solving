class Solution {
    public String solution(String s) {
        String answer = "";
        
        boolean chk = false;
        int len = s.length();
        
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            if (ch == ' ') {
                chk = false;
                answer += ch;
            }
            else if (chk) answer += Character.toLowerCase(ch);
            else {
                chk = true;
                answer += Character.toUpperCase(ch);
            }
        }
        
        return answer;
    }
}