#include <string>
#include <vector>
#include <cmath>
using namespace std;

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };
char dir[] = { 'd', 'l', 'r', 'u' };

string answer;
bool chk[55][55][2525];

bool f(int n, int m, int x, int y, int r, int c, int k, int cnt, string path) {
    
    if (cnt == k) {
        if (x == r && y == c) {
            answer = path;
            return true;
        }
        return false;
    }
    
    if (chk[x][y][cnt]) return false;
    chk[x][y][cnt] = true;
    
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - cnt - dist) % 2) return false;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || n < nx || ny < 1 || m < ny) continue;

        if (f(n, m, nx, ny, r, c, k, cnt + 1, path + dir[i])) return true;
    }
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    answer = "impossible";
    f(n, m, x, y, r, c, k, 0, "");
    
    return answer;
}