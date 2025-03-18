#include <string>
#include <vector>

using namespace std;

#define N 1010101

bool isVisit[N];
vector<int> neighbors[N];

void dfs(int cur, int cnt[2]) {
    bool chk = (cur % 2 == (neighbors[cur].size() % 2));
    
    cnt[chk]++;
    isVisit[cur] = true;
    for (int next : neighbors[cur]) {
        if (isVisit[next]) continue;
        dfs(next, cnt);
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = { 0, 0 };
    
    for (vector<int> edge : edges) {
        int a = edge[0];
        int b = edge[1];
        
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    
    for (int node : nodes) {
        if (isVisit[node]) continue;
        
        int cnt[] = { 0, 0 };
        dfs(node, cnt);
        for (int i = 0; i < 2; i++) {
            if (cnt[i] == 1) answer[!i]++;
        }
    }
    
    return answer;
}