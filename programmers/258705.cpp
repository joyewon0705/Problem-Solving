#include <string>
#include <vector>

using namespace std;

#define N 101010
#define MOD 10007

int solution(int n, vector<int> tops) {
    int answer;
    int d[N][2];
    
    if (tops[0]) {
        d[0][0] = 3;
        d[0][1] = 1;
    }
    else {
        d[0][0] = 2;
        d[0][1] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (tops[i]) {
            d[i][0] = (d[i - 1][0] * 3 + d[i - 1][1] * 2) % MOD;
            d[i][1] = (d[i - 1][0] + d[i - 1][1]) % MOD;
        }
        else {
            d[i][0] = (d[i - 1][0] * 2 + d[i - 1][1]) % MOD;
            d[i][1] = (d[i - 1][0] + d[i - 1][1]) % MOD;
        }
    }
    answer = (d[n - 1][0] + d[n - 1][1]) % MOD;
    
    return answer;
}