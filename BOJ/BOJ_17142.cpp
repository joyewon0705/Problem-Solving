#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 55
#define M 11
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, s, ans = INF;
int map[N][N], chk[M][N][N];
vector<int> av;
vector<P> v;
queue<pair<int, P>> q;

void f(int cur, int cnt) {
	
	if (cur > s) return;
	if (cnt == m) {
		int val = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j]) continue;
				int tmp = INF;
				for (int virus : av) {
					if (chk[virus][i][j] < tmp) tmp = chk[virus][i][j];
				}
				if (tmp >= INF) return;
				if (val < tmp) val = tmp;
				if (val > ans) return;
			}
		}
		if (ans > val) ans = val;
		return;
	}

	av.push_back(cur);
	f(cur + 1, cnt + 1);
	av.erase(av.end() - 1);
	f(cur + 1, cnt);
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) v.push_back({ i, j });
		}
	}

	s = v.size();
	for (int i = 0; i < s; i++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				chk[i][x][y] = INF;
			}
		}

		q.push({ 0, v[i] });
		while (!q.empty()) {
			int cnt = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();

			if (map[x][y] == 1) continue;
			if (chk[i][x][y] <= cnt) continue;
			chk[i][x][y] = cnt;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				q.push({ cnt + 1, { nx, ny } });
			}
		}
	}

	f(0, 0);

	if (ans >= INF) printf("-1");
	else printf("%d", ans);

	return 0;
}