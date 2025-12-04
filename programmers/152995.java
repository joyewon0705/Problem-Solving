import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int n = scores.length;
        int[] target = scores[0];
        
        // 첫 번째 점수 기준으로 내림차순 정렬
        Arrays.sort(scores, (s1, s2) -> Integer.compare(s2[0], s1[0]));
        
        int max = 0;
        int tmp = scores[0][1];
        
        List<Integer> sums = new ArrayList<>();
        sums.add(scores[0][0] + scores[0][1]);
        
        // 인센티브 지급 대상 추리기
        for (int i = 1; i < n; i++) {
            // 최대값 갱신
            if (scores[i][0] < scores[i - 1][0]) {
                max = Math.max(max, tmp);
                tmp = scores[i][1];
            }
            tmp = Math.max(tmp, scores[i][1]);
            
            // 탈락 조건
            if (max > scores[i][1]) {
                if (scores[i][0] == target[0] && scores[i][1] == target[1]) {
                    return -1;
                }
                continue;
            }
            
            sums.add(scores[i][0] + scores[i][1]);
        }
        
        // 내림차순 정렬
        sums.sort((a, b) -> Integer.compare(b, a));
        
        // 순위 계산
        int sum = target[0] + target[1];
        for (int i = 0; i < sums.size(); i++) {
            if (sums.get(i) == sum) {
                return i + 1;
            }
        }
        return -1;
    }
}