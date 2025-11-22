import java.util.*;

class Solution {
    public int solution(int coin, int[] cards) {
        int n = cards.length;
        
        // 카드 값 -> 인덱스 매핑
        int[] valToIdx = new int[n + 1];
        for (int i = 0; i < n; i++) {
            valToIdx[cards[i]] = i;
        }
        
        boolean[] used = new boolean[n];
        int maxIdx = n / 3 + 2;
        int rounds = 1;
        
        // 라운드 진행
        boolean updated = true;
        while (updated) {
            updated = false;
            
            for (int i = 0; i < maxIdx; i++) {
                if (used[i]) continue;
                
                // 짝이 되는 카드 인덱스
                int j = valToIdx[n + 1 - cards[i]];
                if (maxIdx <= j) continue;
                
                // 카드를 뽑는 데 드는 비용
                int cost = (n / 3 <= i ? 1 : 0) + (n / 3 <= j ? 1 : 0);
                if (coin < cost) continue;
                
                coin -= cost;
                used[i] = used[j] = true;
                
                maxIdx = Math.min(maxIdx + 2, n);
                rounds++;
                updated = true;
                break;
            }
        }
        
        // 가능한 최대 라운드 수
        int maxRounds = (n - n / 3) / 2 + 1;
        return Math.min(rounds, maxRounds);
    }
}