#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define N 111

int n, m;
bool chk[N];
int point[N], cnt[N];
vector<int> childs[N], order;

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer = { -1 };
    
    n = edges.size();
    target.insert(target.begin(), 0);
    for (int i = 1; i <= n + 1; i++) {
        point[i] = -1;
        if (target[i] == 0) {
            chk[i] = true;
            m++;
        }
    }
    for (vector<int> edge : edges) {
        int u = edge[0];
        int v = edge[1];
        
        if (point[u]) point[u] = 0;
        childs[u].push_back(v);
    }
    for (int i = 1; i <= n + 1; i++) 
        sort(childs[i].begin(), childs[i].end());
    
    while (true) {
        bool isAnswer = true;
        int cur, next;
        
        cur = 1;
        while (true) {
            if (point[cur] < 0) {
                order.push_back(cur);
                cnt[cur]++;
                if (cnt[cur] * 1 <= target[cur] && target[cur] <= cnt[cur] * 3) {
                    if (!chk[cur]) {
                        chk[cur] = true;
                        m++;
                    }
                }
                else if (target[cur] < cnt[cur] * 1) {
                    isAnswer = false;
                }
                break;
            }
            
            next = childs[cur][point[cur]];
            point[cur] = (point[cur] + 1) % childs[cur].size();
            cur = next;
        }
        
        if (m == n + 1) {
            answer = {};
            break;
        }
        if (!isAnswer) break;
    }
    
    if (answer.empty()) {
        vector<int> vs[N];
        
        for (int i = 1; i <= m; i++) {
            int sum = cnt[i] * 3;
            vs[i] = vector<int>(cnt[i], 3);
            
            for (int j = 0; j < cnt[i]; j++) {
                if (sum == target[i]) break;
                while (sum > target[i] && vs[i][j] > 1) {
                    vs[i][j]--;
                    sum--;
                }
            }
        }
        
        for (int cur : order) {
            answer.push_back(vs[cur][0]);
            vs[cur].erase(vs[cur].begin());
        }
    }
    
    return answer;
}