#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007
#define N 101

int dp[N][N];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for (vector<int> p : puddles) {
        dp[p[1]][p[0]] = -1;
    }
    
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] < 0) dp[i][j] = 0;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    answer = dp[n][m];
    
    return answer;
}