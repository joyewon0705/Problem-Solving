class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 1;

        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        
        while (a % 2 == 0 || a + 1 < b) {
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            answer++;
        }

        return answer;
    }
}