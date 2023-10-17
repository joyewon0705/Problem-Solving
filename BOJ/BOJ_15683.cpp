#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define N 10
typedef pair<int, int> P;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, cnt, ans = N * N;
bool chk[N][N];
int map[N][N];
vector<P> cctv, dir[N];

void f2() {
	int tmp = 0;

	memset(chk, false, sizeof(chk));
	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].first;
		int y = cctv[i].second;
		for (P d : dir[i]) {
			int nx = x;
			int ny = y;
			while (true) {
				nx += d.first;
				ny += d.second;
				if (nx < 1 || n < nx || ny < 1 || m < ny) break;
				if (map[nx][ny] == 6) break;
				if (map[nx][ny]) continue;
				if (chk[nx][ny]) continue;
				chk[nx][ny] = true;
				tmp++;
			}
		}
	}

	if (ans > cnt - tmp) ans = cnt - tmp;
}

void f1(int cur) {

	if (cur >= cctv.size()) {
		f2();
		return;
	}

	int type = map[cctv[cur].first][cctv[cur].second];
	if (type == 1) {
		for (int k = 0; k < 4; k++) {
			dir[cur] = vector<P>();
			dir[cur].push_back({ dx[k], dy[k] });
			f1(cur + 1);
		}
	}
	else if (type == 2) {
		for (int k = 0; k < 2; k++) {
			dir[cur] = vector<P>();
			dir[cur].push_back({ dx[k], dy[k] });
			dir[cur].push_back({ dx[k + 2], dy[k + 2] });
			f1(cur + 1);
		}
	}
	else if (type == 3) {
		for (int k = 0; k < 4; k++) {
			dir[cur] = vector<P>();
			dir[cur].push_back({ dx[k], dy[k] });
			dir[cur].push_back({ dx[(k + 1) % 4], dy[(k + 1) % 4] });
			f1(cur + 1);
		}
	}
	else if (type == 4) {
		for (int k = 0; k < 4; k++) {
			dir[cur] = vector<P>();
			for (int i = 0; i < 4; i++) {
				if (k == i) continue;
				dir[cur].push_back({ dx[i], dy[i] });
			}
			f1(cur + 1);
		}
	}
	else if (type == 5) {
		for (int k = 0; k < 4; k++) {
			dir[cur].push_back({ dx[k], dy[k] });
		}
		f1(cur + 1);
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) cnt++;
			else if (map[i][j] < 6) cctv.push_back({ i, j });
		}
	}

	f1(0);

	printf("%d", ans);

	return 0;
}