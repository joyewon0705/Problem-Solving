#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;
vector<vector<int>> board;

P f(vector<P> loc, int cur, int cnt) {
    int x = loc[cur].first;
    int y = loc[cur].second;
    
    if (board[x][y] == 0) return { cur ? 0 : 1, cnt };
    board[x][y] = 0;
    
    P ret = { cur ? 0 : 1, cnt };
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
        if (board[nx][ny] == 0) continue;
        
        vector<P> nloc = loc;
        nloc[cur] = { nx, ny };
        
        P val = f(nloc, cur ? 0 : 1, cnt + 1);
        
        // 현재 말이 이기는 경우, 이동 횟수가 가장 짧도록
        if (val.first == cur) {
            if ((ret.first == cur && ret.second > val.second) || (ret.first != cur)) 
                ret = val;
        }
        // 현재 말이 지는 경우, 이동 횟수가 길도록
        else {
            if (ret.first != cur&& ret.second < val.second) 
                ret = val;
        }
    }
    
    board[x][y] = 1;
    return ret;
}


int solution(vector<vector<int>> board_in, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    
    board = board_in;
    n = board.size();
    m = board[0].size();
    vector<P> loc = { { aloc[0], aloc[1] }, { bloc[0], bloc[1] } };
    
    answer = f(loc, 0, 0).second;
    
    return answer;
}