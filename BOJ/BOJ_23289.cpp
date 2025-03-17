#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define N 22

typedef pair<int, int> P;
typedef struct _info { int x, y, d; }_info;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int r, c, k, w, x, y, t, cnt;
bool wall[N][N][2], isVisit[N][N];
int map[N][N], add[N][N];
vector<P> v;
vector<_info> h;

void dfs(int x, int y, int d, int v) {

	if (x < 1 || r < x || y < 1 || c < y) return;
	if (isVisit[x][y]) return;
	isVisit[x][y] = true;
	add[x][y] += v;
	if (v == 1) return;

	if (d == 1) {
		if (!wall[x][y][0] && !wall[x - 1][y][1]) dfs(x - 1, y + 1, d, v - 1);
		if (!wall[x][y][1]) dfs(x, y + 1, d, v - 1);
		if (!wall[x + 1][y][0] && !wall[x + 1][y][1]) dfs(x + 1, y + 1, d, v - 1);
	}
	else if (d == 2) {
		if (!wall[x][y][0] && !wall[x - 1][y - 1][1]) dfs(x - 1, y - 1, d, v - 1);
		if (!wall[x][y - 1][1]) dfs(x, y - 1, d, v - 1);
		if (!wall[x + 1][y][0] && !wall[x + 1][y - 1][1]) dfs(x + 1, y - 1, d, v - 1);
	}
	else if (d == 3) {
		if (!wall[x][y - 1][1] && !wall[x][y - 1][0]) dfs(x - 1, y - 1, d, v - 1);
		if (!wall[x][y][0]) dfs(x - 1, y, d, v - 1);
		if (!wall[x][y][1] && !wall[x][y + 1][0]) dfs(x - 1, y + 1, d, v - 1);
	}
	else if (d == 4) {
		if (!wall[x][y - 1][1] && !wall[x + 1][y - 1][0]) dfs(x + 1, y - 1, d, v - 1);
		if (!wall[x + 1][y][0]) dfs(x + 1, y, d, v - 1);
		if (!wall[x][y][1] && !wall[x + 1][y + 1][0]) dfs(x + 1, y + 1, d, v - 1);
	}
}

void f1() {

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j] += add[i][j];
		}
	}
}

void f2() {
	int nmap[N][N] = { 0 };

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			nmap[i][j] += map[i][j];
			for (int k = 1; k <= 4; k += 3) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || r < nx || ny < 1 || c < ny) continue;
				if ((k == 1 && wall[i][j][1]) || (k == 2 && wall[nx][ny][1])
					|| (k == 3 && wall[i][j][0]) || (k == 4 && wall[nx][ny][0])) continue;

				int val = (map[i][j] - map[nx][ny]) / 4;
				nmap[nx][ny] += val;
				nmap[i][j] -= val;
			}
		}
	}
	memcpy(map, nmap, sizeof(map));
}

void f3() {

	for (int i = 1; i <= r; i++) {
		if (map[i][1]) map[i][1]--;
		if (map[i][c]) map[i][c]--;
	}
	for (int j = 2; j < c; j++) {
		if (map[1][j]) map[1][j]--;
		if (map[r][j]) map[r][j]--;
	}
}

bool f5() {

	for (P cur : v) {
		if (map[cur.first][cur.second] < k) return false;
	}
	return true;
}

int main(void) {

	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &t);
			if (t == 5) v.push_back({ i, j });
			else if (t)	h.push_back({ i, j, t });
		}
	}
	scanf("%d", &w);
	for (int i = 0; i < w; i++) {
		scanf("%d %d %d", &x, &y, &t);
		wall[x][y][t] = true;
	}

	for (_info cur : h) {
		memset(isVisit, false, sizeof(isVisit));
		dfs(cur.x + dx[cur.d], cur.y + dy[cur.d], cur.d, 5);
	}

	while (cnt <= 100) {
		f1();
		f2();
		f3();
		cnt++;
		if (f5()) break;
	}

	printf("%d", cnt);

	return 0;
}