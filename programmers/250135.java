class Solution {
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;
        
        int h = ((h1 % 12) * 60 * 60 + m1 * 60 + s1) * 5;
        int m = m1 * 60 * 60 + s1 * 60;
        int s = s1 * 60 * 60;
        if (h == s) answer++;
        if (m == s) answer++;
        if (h == s && m == s) answer--;
        while (h1 != h2 || m1 != m2 || s1 != s2) {
            s1++;
            if (s1 == 60) {
                s1 = 0;
                m1++;
                if (m1 == 60) {
                    m1 = 0;
                    h1++;
                }
            }
            
            int nh = ((h1 % 12) * 60 * 60 + m1 * 60 + s1) * 5;
            int nm = m1 * 60 * 60 + s1 * 60;
            int ns = s1 * 60 * 60;
            if (s < ns) {
                if (s < h && nh <= ns) answer++;
                if (s < m && nm <= ns) answer++;
            }
            else {
                if (s < h || nh <= ns) answer++;
                if (s < m || nm <= ns) answer++;
            }
            if (nh == ns && nm == ns) answer--;
            h = nh;
            m = nm;
            s = ns;
        }
        
        return answer;
    }
}