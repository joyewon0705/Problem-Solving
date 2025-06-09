#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, a, b;
vector<int> v;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    n = scores.size();
    a = scores[0][0];
    b = scores[0][1];
    sort(scores.begin(), scores.end(), greater());
    
    v.push_back(scores[0][0] + scores[0][1]);
    int max = 0, nmax= scores[0][1];
    for (int i = 1; i < n; i++) {
        if (scores[i - 1][0] > scores[i][0]) {
            if (max < nmax) max = nmax;
            nmax = scores[i][1];
        }
        if (nmax < scores[i][1]) nmax = scores[i][1];
        if (max > scores[i][1]) {
            if (scores[i][0] == a && scores[i][1] == b) answer = -1;
            continue;
        }
        v.push_back(scores[i][0] + scores[i][1]);
    }
    
    if (answer > -1) {
        sort(v.begin(), v.end(), greater());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == a + b) {
                answer = i + 1;
                break;
            }
        }
    }
    
    return answer;
}