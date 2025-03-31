class Solution {
    
    public int solution(int n) {
        int answer = 0;
        
        int low, high, val;
        
        low = high = val = 0;
        while (high <= n) {
            if (val < n) {
                high++;
                val += high;
            }
            else if (val > n) {
                low++;
                val -= low;
            }
            else {
                answer++;
                high++;
                low++;
                val = val + high - low;
            }
        }
        
        return answer;
    }
}