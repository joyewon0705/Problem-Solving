class Solution {
    public int solution(int n) {
        int answer = n + 1;
        int cnt = Integer.bitCount(n);
        
        while (true) {
            if (Integer.bitCount(answer) == cnt) break;
            answer++;
        }
        
        return answer;
    }
}