#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007
#define N 101010

int dp[N];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    dp[0] = 1;
    for (int m : money) {
        for (int i = m; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - m]) % MOD;
        }
    }
    answer = dp[n];
    
    return answer;
}