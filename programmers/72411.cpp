#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int maxx[11];
map<string, int> m[11];

void f(int cur, int cnt, string menu, int n, string order) {
    
    if (cnt == n) {
        if (m[n].find(menu) != m[n].end()) m[n][menu]++;
        else m[n].insert({ menu, 1 });
        if (maxx[n] < m[n][menu]) maxx[n] = m[n][menu];
        return;
    }
    if (cur >= order.size()) return;
    
    string nmenu = menu + order[cur];
    f(cur + 1, cnt + 1, nmenu, n, order);
    f(cur + 1, cnt, menu, n, order);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (string order : orders) {
        sort(order.begin(), order.end());
        for (int n : course) f(0, 0, "", n, order);
    }
    
    for (int n : course) {
        if (maxx[n] < 2) continue;
        for (pair<string, int> cur : m[n]) {
            if (cur.second == maxx[n]) answer.push_back(cur.first);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}