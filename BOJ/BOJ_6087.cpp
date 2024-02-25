#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 111
typedef struct _info { int x, y, cnt, dir; }_info;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int w, h, a, b, c, d, ans;
int m[N][N][4];
queue <_info> q;

int main(void) {

	scanf("%d %d\n", &w, &h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			ch = getchar();
			int val = INF;
			if (ch == '*') val = -1;
			else if (ch == 'C') {
				if (a == 0) { a = i; b = j; }
				else { c = i, d = j; }
			}
			for (int k = 0; k < 4; k++) m[i][j][k] = val;
		}
		getchar();
	}

	ans = INF;
	for (int k = 0; k < 4; k++) q.push({ a, b, 0, k });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int dir = q.front().dir;
		q.pop();

		if (x == c && y == d) {
			if (ans > cnt) ans = cnt;
			continue;
		}

		if (x < 1 || h < x || y < 1 || w < y) continue;
		if (m[x][y][dir] <= cnt) continue;
		m[x][y][dir] = cnt;

		q.push({ x + dx[dir], y + dy[dir], cnt, dir });
		if (dir > 1) {
			q.push({ x + dx[0], y + dy[0], cnt + 1, 0 });
			q.push({ x + dx[1], y + dy[1], cnt + 1, 1 });
		}
		else {
			q.push({ x + dx[2], y + dy[2], cnt + 1, 2 });
			q.push({ x + dx[3], y + dy[3], cnt + 1, 3 });
		}
	}

	printf("%d", ans);

	return 0;
}