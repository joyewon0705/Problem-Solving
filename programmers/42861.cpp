#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N 101

typedef pair<int, int> P;

bool chk[N];
vector<P> edges[N];
priority_queue<P, vector<P>, greater<>> pq;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (vector<int> cost : costs) {
        edges[cost[0]].push_back({ cost[2], cost[1] });
        edges[cost[1]].push_back({ cost[2], cost[0] });
    }
 
    pq.push({ 0, 0 });
    while (n) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (chk[cur]) continue;
        chk[cur] = true;
        
        n--;
        answer += cost;
        for (P edge : edges[cur]) pq.push(edge);
    }
    
    return answer;
}