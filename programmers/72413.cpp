#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define INF 1<<30
#define N 202

int answer;
int cost[N][N];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }
    for (vector<int> fare : fares) {
        cost[fare[0]][fare[1]] = fare[2];
        cost[fare[1]][fare[0]] = fare[2];
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == i || cost[i][k] >= INF) continue;
            for (int j = i + 1; j <= n; j++) {
                if (k == j || cost[k][j] >= INF) continue;
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                cost[j][i] = cost[i][j];
            }
        }
    }
    
    answer = INF;
    for (int k = 1; k <= n; k++) {
        if (cost[s][k] >= INF || cost[k][a] >= INF || cost[k][b] >= INF) continue;
        answer = min(answer, cost[s][k] + cost[k][a] + cost[k][b]);
    }
    
    return answer;
}