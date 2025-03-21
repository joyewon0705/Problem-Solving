#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define LEN 12

typedef long long ll;

int len;
ll cnt;
ll m[LEN];
vector<string> v[LEN], cv;

string solution(long long n, vector<string> bans) {
    string answer = "";
   
    for (string cur : bans) {
        v[cur.length()].push_back(cur);
    }

    m[0] = 1;
    for (ll i = 1; i < LEN; i++) {
        sort(v[i].begin(), v[i].end());
        m[i] = m[i - 1] * 26;
        cnt += m[i] - v[i].size();
        if (cnt >= n) {
            cnt -= m[i] - v[i].size();
            len = i;
            cv = v[i];
            break;
        }
    }
   
    while (len--) {
        for (int i = 1, j = 0; i <= 26; i++) {
            int nc = 0;
            vector<string> nv;
            while (j < cv.size() && cv[j][0] == 'a' + i - 1) {
                string cur = cv[j++];
                nc++;
                cur.erase(0, 1);
                nv.push_back(cur);
            }
            cnt += m[len] - nc;
            if (cnt >= n) {
                answer.push_back('a' + i - 1);
                cnt -= m[len] - nc;
                cv = nv;
                sort(cv.begin(), cv.end());
                break;
            }
        }
    }
   
    return answer;
}
