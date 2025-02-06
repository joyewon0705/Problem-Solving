#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 55

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, d, c, ans = INF;
bool chk[N * N];
int map[N][N];
vector<P> v;

void f(int cur, int cnt) {

	if (cnt == m) {
		int ta = 0, tc = c;
		bool isVisit[N][N] = { false };
		queue<pair<int, P>> q;

		for (int i = 0; i < v.size(); i++) {
			if (chk[i]) q.push({ 0, v[i] });
		}

		while (!q.empty()) {
			int s = q.front().first;
			P cur = q.front().second;
			q.pop();

			if (isVisit[cur.first][cur.second]) continue;
			isVisit[cur.first][cur.second] = true;

			if (map[cur.first][cur.second] == 0) {
				tc--;
				if (ta < s) ta = s;
			}

			for (int k = 0; k < 4; k++) {
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (map[nx][ny] == 1) continue;
				q.push({ s + 1, { nx,  ny } });
			}
		}

		if (tc == 0 && ans > ta) ans = ta;

		return;
	}
	else if (cur >= v.size()) return;
	else {
		chk[cur] = true;
		f(cur + 1, cnt + 1);
		chk[cur] = false;
		f(cur + 1, cnt);
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d);
			if (d == 1) map[i][j] = 1;
			else if (d == 2) {
				map[i][j] = -1;
				v.push_back({ i, j });
			}
			else c++;
		}
	}

	f(0, 0);
	
	if (ans == INF) ans = -1;
	printf("%d", ans);

	return 0;
}