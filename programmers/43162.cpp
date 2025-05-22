#include <string>
#include <vector>
#include <queue>
using namespace std;

#define N 202

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool isVisit[N] = { false };
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (isVisit[i]) continue;
        
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (isVisit[cur]) continue;
            isVisit[cur] = true;
            
            for (int j = 0; j < n; j++) {
                if (computers[cur][j]) q.push(j);
            }
        }
        answer++;
    }
    
    return answer;
}