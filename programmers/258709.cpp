#include <string>
#include <vector>

using namespace std;

#define M 1<<11

int n, l, chk;
int sum[M][505], win[M];
vector<int> v, answer;
vector<vector<int>> _dice;

void f1(int cur, int cnt, int val, vector<int> v) {
    
    if (cnt == n / 2) {
        for (int a : v) sum[val][a]++;
        return;
    }
    if (cur >= n) return;
    
    vector<int> nv = {};
    for (int a : v) {
        for (int b : _dice[cur]) {
            nv.push_back(a + b);
        }
    }
    f1(cur + 1, cnt + 1, val | (1 << cur), nv);
    f1(cur + 1, cnt, val, v);
}

void f2(int cur, int cnt, int val) {
    
    if (cnt == n / 2) {
        int nval = 0;
        for (int i = 0; i < n; i++) {
            if ((val & 1<<i) == 0) nval |= 1<<i;
        }
        
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i; j++) {
                win[val] += sum[val][i] * sum[nval][j];
            }
        }
        return;
    }
    if (cur >= n) return;
    
    f2(cur + 1, cnt + 1, val | 1<<cur);
    f2(cur + 1, cnt, val);
}

void f3(int cur, int cnt, int val, vector<int> v) {
    
    if (cnt == n / 2) {
        if (win[chk] < win[val]) {
            chk = val;
            answer = v;
        }
        return;
    }
    if (cur >= n) return;
    
    v.push_back(cur + 1);
    f3(cur + 1, cnt + 1, val | 1<<cur, v);
    v.erase(v.end() - 1);
    f3(cur + 1, cnt, val, v);
}

vector<int> solution(vector<vector<int>> dice) {
    
    n = dice.size();
    _dice = dice;
    l = 101 * (n / 2);
    printf("n = %d\n", n);
    
    v.push_back(0);
    f1(0, 0, 0, v);
    
    f2(0, 0, 0);
    
    v = {};
    f3(0, 0, 0, v);
    
    return answer;
}