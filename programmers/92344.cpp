#include <string>
#include <vector>

using namespace std;

#define N 1010

int n, m;
int c[N][N], d[N][N];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    n = board.size();
    m = board[0].size();
    for (vector<int> s : skill) {
        int degree = s[0] == 1 ? -s[5] : s[5];
        c[s[1]][s[2]] += degree;
        c[s[1]][s[4] + 1] -= degree;
        c[s[3] + 1][s[2]] -= degree;
        c[s[3] + 1][s[4] + 1] += degree;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i) c[i][j] += c[i - 1][j];
            d[i][j] = c[i][j];
            if (j) d[i][j] += d[i][j - 1];
            board[i][j] += d[i][j];
            if (board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}