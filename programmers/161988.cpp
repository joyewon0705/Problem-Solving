#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define N 505050

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long n, sum1, sum2;
    
    n = sequence.size();
    sum1 = sum2 = 0;
    for (int i = 0; i < n; i++) {
        long long cur = sequence[i];
        if (i % 2) {
            sum1 = max(sum1 + cur, cur);
            sum2 = max(sum2 - cur, -cur);
        }
        else {
            sum1 = max(sum1 - cur, -cur);
            sum2 = max(sum2 + cur, cur);
        }
        answer = max(answer, max(sum1, sum2));
    }
    
    return answer;
}
