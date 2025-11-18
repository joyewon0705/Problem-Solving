import java.util.*;
import java.util.stream.*;

class Solution {
    private static final int MAX = 101;
    
    private int n;
    private int maxWin = 0;
    private int fullMask;
    private boolean[] visited;
    private int[] answer;
    private int[][] dices;
    
    public int[] solution(int[][] dice) {
        this.n = dice.length;
        this.fullMask = (1 << n) - 1;
        this.visited = new boolean[1 << (n + 1)];
        this.answer = new int[n / 2];
        this.dices = dice;
        
        searchCombination(0, 0, 0);
        return answer;
    }
    
    // 조합 탐색: n개 중 n/2개 고르기
    private void searchCombination(int cur, int cnt, int mask) {
        if (cnt == n / 2) {
            if (visited[mask]) return;
            
            visited[mask] = true;
            visited[(~mask) & fullMask] = true;
                
            int[] score = calculateScore(mask);
            
            if (maxWin < score[0]) {
                maxWin = score[0];
                answer = extractDice(mask);
            }
            if (maxWin < score[1]) {
                maxWin = score[1];
                answer = extractDice((~mask) & fullMask);
            }
            return;
        }
        if (cur == n) return;
        
        // 선택하는 경우
        searchCombination(cur + 1, cnt + 1, mask | (1 << cur));
        // 선택하지 않는 경우
        searchCombination(cur + 1, cnt, mask);
    }
    
    // 그룹에 속하는 주사위 목록 추출
    private int[] extractDice(int mask) {
        int[] result = new int[n / 2];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                result[idx++] = i + 1;
            }
        }
        return result;
    }
    
    // 두 그룹의 승리 횟수 계산
    private int[] calculateScore(int mask) {
        int maxSum = (n / 2) * 100 + 1;
        int[] sumA = new int[maxSum];
        int[] sumB = new int[maxSum];
        int[] result = { 0, 0 };
        
        countSum(0, 0, mask, sumA);
        countSum(0, 0, (~mask) & fullMask, sumB);
        
        for (int i = 0; i < maxSum; i++) {
            for (int j = 0; j < maxSum; j++) {
                if (i > j) {
                    result[0] += sumA[i] * sumB[j];
                }
                else if (i < j) {
                    result[1] += sumA[i] * sumB[j];
                }
            }
        }
        return result;
    }
    
    // 해당 그룹에서 가능한 합의 경우의 수 카운팅
    private void countSum(int cur, int sum, int mask, int[] list) {
        if (cur == n) {
            list[sum]++;
            return;
        }
        
        if ((mask & (1 << cur)) != 0) {
            // 해당 주사위가 포함되는 경우
            for (int i = 0; i < 6; i++) {
                countSum(cur + 1, sum + dices[cur][i], mask, list);
            }
        }
        else {
            // 해당 주사위가 포함되지 않는 경우
            countSum(cur + 1, sum, mask, list);
        }
    }
}