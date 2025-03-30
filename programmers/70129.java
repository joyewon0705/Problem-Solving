class Solution {
    public int[] solution(String s) {
        int[] answer = { 0, 0 };
        
        while (!s.equals("1")) {
            answer[0]++;
            String ns = s.replace("0", "");
            answer[1] += s.length() - ns.length();
            s = Integer.toBinaryString(ns.length());
        }
        
        return answer;
    }
}