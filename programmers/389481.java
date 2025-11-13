import java.util.Arrays;

class Solution {
    private final int N = 'z' - 'a' + 1;
    
    public String solution(long n, String[] bans) {
        // bans를 수로 변경 및 정렬
        long[] bannedNumbers = Arrays.stream(bans)
            .mapToLong(this::encode)
            .sorted()
            .toArray();
        
        // 정답인 수 계산
        for (long num : bannedNumbers) {
            if (num <= n) n++;
            else break;
        }
        
        // 해당 수를 문자로 변경
        return decode(n);
    }
    
    private long encode(String s) {
        long value = 0;
        long base = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            value += base * (s.charAt(i) - 'a' + 1);
            base *= N;
        }
        return value;
    }
    
    private String decode(long n) {
        StringBuilder sb = new StringBuilder();
        do {
            n--;
            sb.append((char) ('a' + n % N));
            n /= N;
        } while (n > 0);
        return sb.reverse().toString();
    }
}