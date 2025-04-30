#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> P;

void setIn(int n, int h, int m, vector<P>& history) {
    
    for (int i = 0; i < history.size(); i++) {
        if (n == history[i].first) {
            history[i].second = h * 60 + m;
            return;
        }
    }
    history.push_back({ n, h * 60 + m });
}

int setOut(int n, int h, int m, vector<P>& history) {
    
    for (int i = 0; i < history.size(); i++) {
        if (n == history[i].first) {
            int t = h * 60 + m - history[i].second;
            history[i].second = -1;
            return t;
        }
    }
}

void setTime(int n, int t, vector<P>& ctime) {
    
    for (int j = 0; j < ctime.size(); j++) {
        if (n == ctime[j].first) {
            ctime[j].second += t;
            return;
        }
    }
    ctime.push_back({ n, t });
}

bool cmp(P a, P b) {
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<P> history, ctime;
    
    // 누적 시간 계산
    for (string record : records) {
        int h, m, n;
        char s[4];
        sscanf(record.c_str(), "%d:%d %d %s", &h, &m, &n, s);
        if (s[0] == 'I') {
            setIn(n, h, m, history);
        }
        else {
            int t = setOut(n, h, m, history);
            setTime(n, t, ctime);
        }
    }
    
    // 출차된 내역이 없는 차량 누적 시간 계산
    for (P cur : history) {
        if (cur.second > -1) {
            int n = cur.first;
            int t = 23 * 60 + 59 - cur.second;
            setTime(n, t, ctime);
        }
    }
    
    // 정렬
    sort(ctime.begin(), ctime.end(), cmp);
    
    // 주차 요금 계산
    for (P cur : ctime) {   
        int t = cur.second;
        int charge = fees[1];
        if (t > fees[0]) {
            charge += ceil((double)(t - fees[0]) / fees[2])  * fees[3];
        }
        answer.push_back(charge);
    }
    
    return answer;
}