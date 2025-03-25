class Solution {
    
    final int INF = 1<<30;
    
    public String solution(String s) {
        char c;
        int min = INF, max = -INF, val;
        String number = "", answer = "";
        
        for (int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            
            if (c == ' ') {
                val = Integer.parseInt(number);
                if (min > val) min = val;
                if (max < val) max = val;
                number = "";
            }
            else number += c;
        }
        val = Integer.parseInt(number);
        if (min > val) min = val;
        if (max < val) max = val;
            
        answer = Integer.toString(min) + " " + Integer.toString(max);
        
        return answer;
    }
}