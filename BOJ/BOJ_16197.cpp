#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 22
typedef pair<int, int> P;
typedef struct _info { int a, b, c, d, cnt; } _info;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int n, m, a, b, c, d, ans = -1;
bool isVisit[N][N][N][N], map[N][N];
queue<_info> q;

P move(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 1 || n < nx || ny < 1 || m < ny || map[nx][ny]) return { nx, ny };
	else return { x, y };
}

int chk(int x, int y) {

	if (x < 1 || n < x || y < 1 || m < y) return 1;
	else return 0;
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			if (ch == 'o') {
				if (a) { c = i; d = j; }
				else { a = i; b = j; }
			}
			else if (ch == '#') continue;
			map[i][j] = true;
		}
	}

	q.push({ a, b, c, d, 0 });
	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		int d = q.front().d;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt > 10) continue;

		int t = chk(a, b) + chk(c, d);
		if (t == 1) {
			ans = cnt;
			break;
		}
		if (t == 2) continue;
		if (isVisit[a][b][c][d]) continue;
		isVisit[a][b][c][d] = true;

		for (int k = 0; k < 4; k++) {
			P c1 = move(a, b, k);
			P c2 = move(c, d, k);
			q.push({ c1.first, c1.second, c2.first, c2.second, cnt + 1 });
		}
	}

	printf("%d", ans);

	return 0;
}