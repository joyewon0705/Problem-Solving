class Solution {
    
    final int N = 101;
    
    public int solution(int[] arr) {
        int answer;
        boolean []isPrime = new boolean[N];
        int []div = new int[N];
        
        for (int i = 2; i < N; i++) isPrime[i] = true;
        
        for (int i = 2; i * i < N; ) {
            while (!isPrime[++i]);
            for (int j = i + 1; j < N; j++) {
                if (j % i == 0) isPrime[j] = false;
            }
        }
        
        for (int cur : arr) {
            int prm, cnt;
            
            prm = 2;
            while (cur > 1) {
                while (cur % prm > 0) {
                    while (!isPrime[++prm]);
                }
                
                cnt = 0;
                while (!(cur % prm > 0)) {
                    cur /= prm;
                    cnt++;
                }
                if (div[prm] < cnt) div[prm] = cnt;
            }
        }
        
        answer = 1;
        for (int i = 2; i < N; i++) {
            for (int j = 0; j < div[i]; j++) {
                answer *= i;
            }
        }
        
        return answer;
    }
}