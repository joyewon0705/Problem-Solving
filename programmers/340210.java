import java.util.*;

class Solution {
    private int n;
    private String[][] tokens;
    private List<Integer> known = new ArrayList<>();
    private List<Integer> unknown = new ArrayList<>();
    
    public String[] solution(String[] expressions) {
        n = expressions.length;
        tokens = new String[n][5];
        
        for (int i = 0; i < n; i++) {
            // 수식을 공백 기준으로 분리한 토큰 저장
            tokens[i] = expressions[i].split(" ");
            
            // 결과가 주어진 식과 X로 표시된 식 저장
            if (expressions[i].contains("X")) {
                unknown.add(i);
            } else {
                known.add(i);
            }
        }
        
        // 가능한 진법 탐색
        int minBase = findMaxDigit(expressions) + 1;
        for (int base = minBase; base < 10; base++) {
            boolean validBase = validateBase(base);
            
            if (validBase) {
                // 해당 진법이 가능한 경우
                fillUnknown(base);
            }
        }
        
        // 정답 추출 및 반환
        List<String> answer = new ArrayList<>();
        for (int idx : unknown) {
            answer.add(String.join(" ", tokens[idx]));
        }
        return answer.toArray(String[]::new);
    }
    
    // 수식 중 가장 큰 숫자 찾기
    private int findMaxDigit(String[] expressions) {
        int max = 0;
        for (String exp : expressions) {
            for (char c : exp.toCharArray()) {
                if (Character.isDigit(c)) {
                    max = Math.max(max, c - '0');
                }
            }
        }
        return max;
    }
    
    // 해당 진법이 성립하는지 검사
    private boolean validateBase(int base) {
        for (int idx : known) {
            String[] t = tokens[idx];
            int a = toDemical(t[0], base);
            int b = toDemical(t[2], base);
            int c = t[1].equals("+") ? a + b : a - b;

            if (!t[4].equals(fromDemical(c, base))) {
                return false;
            }
        }
        return true;
    }
    
    // X 값 채우기
    private void fillUnknown(int base) {
        for (int idx : unknown) {
            String[] t = tokens[idx];
            int a = toDemical(t[0], base);
            int b = toDemical(t[2], base);
            int c = t[1].equals("+") ? a + b : a - b;
            String expected = fromDemical(c, base);

            if (t[4].equals("X")) {
                t[4] = expected;
            } else if (!t[4].equals(expected)) {
                t[4] = "?";
            }
        }
    }
    
    // 특정 진법 문자열을 10진법 정수로 변환
    private int toDemical(String s, int base) {
        return Integer.parseInt(s, base);
    }
    
    // 10진법 정수를 특정 진법 문자열로 변환
    private String fromDemical(int n, int base) {
        return Integer.toString(n, base);
    }
}