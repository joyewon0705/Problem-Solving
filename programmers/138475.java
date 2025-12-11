import java.util.*;

class Solution {
    
    public int[] solution(int e, int[] starts) {
        int min = Arrays.stream(starts).min().orElse(Integer.MAX_VALUE);
        
        int[] count = new int[e + 2];   // i의 등장 횟수
        int[] maxIdx = new int[e + 2];  // i 이상 e 이하에서 가장 많이 등장한 수
        
        for (int i = e; i >= min; i--) {
            count[i] = countDivisors(i);
            
            int next = maxIdx[i + 1];
            if (count[next] <= count[i]) {
                maxIdx[i] = i;
            } else {
                maxIdx[i] = next;
            }
        }
        
        int[] answer = new int[starts.length];
        for (int i = 0; i < starts.length; i++) {
            answer[i] = maxIdx[starts[i]];
        }
        return answer;
    }
    
    // n의 약수 개수 계산
    private int countDivisors(int n) {
        Map<Integer, Integer> factors = factorize(n);
        
        int result = 1;
        for (int e : factors.values()) {
            result *= (e + 1);
        }
        return result;
    }
    
    // n의 소인수분해 결과를 Map<소수, 지수> 형태로 반환
    private Map<Integer, Integer> factorize(int n) {
        Map<Integer, Integer> factorMap = new HashMap<>();
        
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                factorMap.put(i, factorMap.getOrDefault(i, 0) + 1);
                n /= i;
            }
        }
        
        // 마지막 남은 수가 소수인 경우
        if (n > 1) {
            factorMap.put(n, 1);
        }
        
        return factorMap;
    }
}