#include <iostream>

#define N 13
#define K 11

typedef struct _info { int x, y, d, u, l; }_info;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

bool chk = true;
int n, k, x, y, d, ans;
int map1[N][N], map2[N][N];
_info pieces[K];

void reverse(int x, int b) {
	if (pieces[x].l == b) pieces[x].l = 0;
	if (pieces[x].u == 0) {
		pieces[x].u = b;
		pieces[b].u = x;
	}
	else reverse(pieces[x].u, b);

	int u = pieces[x].u;
	pieces[x].u = pieces[x].l;
	pieces[x].l = u;
}

int move(int x, int nx, int ny) {
	pieces[x].x = nx;
	pieces[x].y = ny;
	if (pieces[x].u == 0) return x;
	else return move(pieces[x].u, nx, ny);
}

int count(int x) {
	if (pieces[x].l == 0) return 1;
	else return count(pieces[x].l) + 1;
}

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map1[i][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &x, &y, &d);
		map2[x][y] = i;
		pieces[i] = { x, y, d, 0, 0 };
	}

	while (chk && ans++ < 1000) {

		for (int i = 1; i <= k; i++) {
			x = pieces[i].x; y = pieces[i].y; d = pieces[i].d;
			int nx = x + dx[d], ny = y + dy[d];

			if (map1[nx][ny] == 2 || nx < 1 || n < nx || ny < 1 || n < ny) {
				pieces[i].d = d = d % 2 ? d + 1 : d - 1;
				nx = x + dx[d]; ny = y + dy[d];
				if (map1[nx][ny] == 2 || nx < 1 || n < nx || ny < 1 || n < ny) continue;
			}

			int top = move(i, nx, ny);
			map2[x][y] = pieces[i].l;
			if (pieces[i].l) {
				pieces[pieces[i].l].u = 0;
				pieces[i].l = 0;
			}
			if (map2[nx][ny]) {
				pieces[map2[nx][ny]].u = i;
				pieces[i].l = map2[nx][ny];
				if (count(top) >= 4) chk = false;
			}
			map2[nx][ny] = top;

			if (map1[nx][ny] == 1 && pieces[i].u) {
				reverse(i, pieces[i].l);
				map2[nx][ny] = i;
			}
		}
	}

	if (ans > 1000) ans = -1;
	printf("%d", ans);

	return 0;
}