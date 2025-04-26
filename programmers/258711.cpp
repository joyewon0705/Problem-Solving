#include <string>
#include <vector>
#include <queue>
using namespace std;

#define N 1010101

bool chk[N];
vector<int> in[N], out[N];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = { 0, 0, 0, 0 };
    
    for (vector<int> edge : edges) {
        out[edge[0]].push_back(edge[1]);
        in[edge[1]].push_back(edge[0]);
    }
    
    for (int i = 1; i < N; i++) {
        if (in[i].size() == 0 && out[i].size() >= 2) {
            answer[0] = i;
            chk[i] = true;
        }
        if (chk[i] || (out[i].size() == 0 && in[i].size() == 0)) continue;
        
        int node = 0, edge = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (chk[cur]) continue;
            chk[cur] = true;
            node++;
            
            for (int next : out[cur]) {
                q.push({ next });
                edge++;
            }
        }
        if (node == edge) answer[1]++;
        else if (node < edge) answer[3]++;
        else {
            answer[2]++;
            chk[i] = false;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (chk[cur]) continue;
                chk[cur] = true;
                
                for (int next : in[cur]) q.push({ next });
            }
        }
    }
    
    return answer;
}