#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define N 151

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer, max_alp, max_cop;
    int dp[N][N];
    
    max_alp = alp, max_cop = cop;
    for (vector<int> problem : problems) {
        if (max_alp < problem[0]) max_alp = problem[0];
        if (max_cop < problem[1]) max_cop = problem[1];
    }
    
    for (int i = alp; i <= max_alp; i++) {
        for (int j = cop; j <= max_cop; j++) {
            dp[i][j] = i - alp + j - cop;
        }
    }
    
    for (int i = alp; i <= max_alp; i++) {
        for (int j = cop; j <= max_cop; j++) {
            if (i > alp && dp[i][j] > dp[i - 1][j] + 1) dp[i][j] = dp[i - 1][j] + 1;
            if (j > cop && dp[i][j] > dp[i][j - 1] + 1) dp[i][j] = dp[i][j - 1] + 1;
            
            for (vector<int> problem : problems) {
                if (i >= problem[0] && j >= problem[1]) {
                    int na = min(max_alp, i + problem[2]);
                    int nc = min(max_cop, j + problem[3]);
                    
                    if (dp[na][nc] > dp[i][j] + problem[4])
                        dp[na][nc] = dp[i][j] + problem[4];
                }
            }
        }
    }
    answer = dp[max_alp][max_cop];
    
    return answer;
}