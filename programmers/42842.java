class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = { 0, 0 };
        
        for (int i = 1; i * i <= yellow; i++) {
            if (yellow % i > 0) continue;
            
            int j = yellow / i;
            if (2 * (i + j) + 4 == brown) {
                answer[0] = j + 2;
                answer[1] = i + 2;
                break;
            }
        }
        
        return answer;
    }
}