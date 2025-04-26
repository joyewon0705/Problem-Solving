#include <string>
#include <vector>

using namespace std;

int m, ans1, ans2;
int sale[7];

void f(int cur, vector<vector<int>> users, vector<int> emoticons) {
    
    if (cur == m) {
        int res1 = 0; 
        int res2 = 0;
        for (vector<int> user : users) {
            int ratio = user[0];
            int price = user[1];
            int sum = 0;
            for (int i = 0; i < m; i++) {
                if (sale[i] >= ratio)
                    sum += emoticons[i] - (emoticons[i] / 100 * sale[i]);
            }
            if (sum >= price) res1++;
            else res2 += sum;
        }
        if (ans1 < res1 || ((ans1 == res1) && (ans2 < res2))) {
            ans1 = res1;
            ans2 = res2;
        } 
        return;
    }
    
    for (int i = 10; i <= 40; i += 10) {
        sale[cur] = i;
        f(cur + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    m = emoticons.size();
    
    f(0, users, emoticons);
    
    answer = { ans1, ans2 };
    
    return answer;
}