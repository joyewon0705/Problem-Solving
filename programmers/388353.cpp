#include <string>
#include <vector>
#include <cstring>
using namespace std;

#define N 55

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;
bool isVisit[N][N];

bool chk(int x, int y, vector<string> &storage) {
    
    if (storage[x][y] == '0') return true;
    
    if (isVisit[x][y]) return false;
    isVisit[x][y] = true;

    if (storage[x][y] == '1') {    
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || n <= nx || ny < 0 || m <= ny || chk(nx, ny, storage)) {
                storage[x][y] = '0';
                return true;
            }
        }
    }
    return false;
}

int useForklift(char c, vector<string> &storage) {
    int cnt = 0;
    vector<P> v;
    
    memset(isVisit, false, sizeof(isVisit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != c) continue;
            
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if (nx < 0 || n <= nx || ny < 0 || m <= ny || 
                    chk(nx, ny, storage)) {
                    v.push_back({ i, j });
                    break;
                }
            }
        }
    }
    
    for (P cur : v) {
        storage[cur.first][cur.second] = '0';
        cnt++;
    }
    return cnt;
}

int useCrane(char c, vector<string> &storage) {
    int cnt = 0;
    vector<P> v;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == c) v.push_back({ i, j });
        }
    }
    
    for (P cur : v) {
        storage[cur.first][cur.second] = '1';
        cnt++;
    }
    return cnt;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer;
    
    n = storage.size();
    m = storage[0].size();
    answer = n * m;
    for (string request : requests) {
        if (request.size() < 2)  {
            answer -= useForklift(request[0], storage);
        }
        else {
            answer -= useCrane(request[0], storage);
        }
    }
    
    return answer;
}