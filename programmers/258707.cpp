#include <string>
#include <vector>

using namespace std;

#define N 1010

int n, cur, cnt;
bool chk[N];
int val[N];

int solution(int coin, vector<int> cards) {
    int answer = 0;
    
    n = cards.size();
    for (int i = n; i >= 0; i--) {
        if (val[i]) continue;
        for (int j = i - 1; j >= 0; j--) {
            if (cards[i] + cards[j] == n + 1) {
                val[i] = j, val[j] = i;
            }
        }
    }
    
    cur = n / 3;
    for (int i = 0; i < n / 3; i++) {
        chk[i] = true;
        if (chk[i] && chk[val[i]]) cnt++;
    }
    
    answer = 1;
    while (true) {
        
        // 코인 1개 소모하는 경우
        while (cur < n) {
            for (int i = cur; i <= cur + 1; i++) {
                if (chk[i]) continue;
                if (coin && chk[val[i]]) {
                    coin--;
                    chk[i] = true;
                    cnt++;
                }
            }
            
            if (cnt) cnt--;
            else break;
            
            cur += 2;
            answer++;
        }
        
        if (coin < 2 || cur >= n) break;
        
        // 코인 2개 소모하는 경우
        for (int i = cur + 1; i >= n / 3; i--) {
            if (chk[i]) continue;
            if (val[i] < i) {
                coin -= 2;
                chk[i] = chk[val[i]] = true;
                cnt++;
                break;
            }
        }
        
        if (cnt == 0) break;
    }
    
    return answer;
}