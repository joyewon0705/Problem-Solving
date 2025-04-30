#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int score, cmp;
int chk[11];
vector<int> answer = vector<int>(11, 0);

void f(int cur, int cnt, int sco, int sum, int n, vector<int>& info) {
    
    if (cur > 10) {
        if (score < sco || (score == sco && cmp > sum)) {
            score = sco;
            cmp = sum;
            for (int i = 0; i < 11; i++) {
                answer[i] = chk[i];
            }
            if (cnt < n) answer[0] += n - cnt;
        }
        return;
    }
    
    if (info[cur] < n - cnt) {
        chk[cur] = info[cur] + 1;
        f(cur + 1, cnt + chk[cur], sco + cur, sum + cur * chk[cur], n, info);
        chk[cur] = 0;
    }
    if (info[cur]) f(cur + 1, cnt, sco - cur, sum, n, info);
    else f(cur + 1, cnt, sco, sum, n, info);
}

vector<int> solution(int n, vector<int> info) {
    
    reverse(info.begin(), info.end());
    
    f(0, 0, 0, 0, n, info);
    
    if (score) reverse(answer.begin(), answer.end());
    else answer = { -1 };
    
    return answer;
}