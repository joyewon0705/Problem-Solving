#include <string>
#include <vector>

using namespace std;

#define N 17

int answer;
vector<int> info_global;
vector<int> tree[N];

void f(int sheep, int wolf, vector<int> visitable) {
    
    if (answer < sheep) answer = sheep;
    
    for (int i = 0; i < visitable.size(); i++) {
        int cur = visitable[i];
        int nsheep = sheep;
        int nwolf = wolf;
        
        if (info_global[cur]) nwolf++;
        else nsheep++;
        
        if (nsheep <= nwolf) continue;
        
        vector<int> nvisitable = visitable;
        nvisitable.erase(nvisitable.begin() + i);
        for (int next : tree[cur]) nvisitable.push_back(next);
        
        f(nsheep, nwolf, nvisitable);
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    info_global = info;
    for (vector<int> edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }
    
    f(1, 0, tree[0]);
    
    return answer;
}