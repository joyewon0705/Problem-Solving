#include <iostream>
#include <queue>
using namespace std;

#define N 22
typedef pair<int, int> P;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int n, m, k, x, y, d, no, ans;
int map[N][N], set[N][N], score[N * N], dice[6] = { 2, 4, 1, 3, 5, 6 };
queue<P> q;

void moveDice(int d) {
	int tmp = dice[5];

	switch (d) {
		case 0:
			dice[5] = dice[3];
			dice[3] = dice[2];
			dice[2] = dice[1];
			dice[1] = tmp;
			break;
		case 1:
			dice[5] = dice[4];
			dice[4] = dice[2];
			dice[2] = dice[0];
			dice[0] = tmp;
			break;
		case 2:
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = tmp;
			break;
		case 3:
			dice[5] = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[4];
			dice[4] = tmp;
			break;
	}
}

void getSet(int x, int y, int b) {
	int c = 0;

	no++;
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (set[x][y]) continue;
		set[x][y] = no;
		c++;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			if (map[nx][ny] == b) q.push({ nx, ny });
		}
	}
	score[no] = b * c;
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	x = y = 1;
	for (int i = 0; i < k; i++) {
		x += dx[d];
		y += dy[d];

		if (x < 1 || n < x || y < 1 || m < y) {
			d = (d + 2) % 4;
			x += 2 * dx[d];
			y += 2 * dy[d];
		}
		moveDice(d);

		if (!set[x][y]) getSet(x, y, map[x][y]);

		ans += score[set[x][y]];
		if (dice[5] > map[x][y]) d = (d + 1) % 4;
		else if (dice[5] < map[x][y]) d = (d + 3) % 4;
	}

	printf("%d", ans);

	return 0;
}