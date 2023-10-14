#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N 7
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int ans;
bool isVisit[N][N], chk[N][N];
char map[N][N];
vector<P> v;
queue<P> q;

void f(int cur, int s, int y) {

	if (y > 3) return;
	if (s + y == 7) {
		memset(chk, false, sizeof(chk));
		int cnt = 7;

		q.push({ v[cur].first, v[cur].second });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (chk[x][y]) continue;
			chk[x][y] = true;
			cnt--;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (isVisit[nx][ny]) q.push({ nx, ny });
			}
		}

		if (cnt) return;
		ans++;
		return;
	}

	for (int k = cur + 1; k < 25; k++) {
		int i = v[k].first;
		int j = v[k].second;

		isVisit[i][j] = true;
		if (map[i][j] == 'S') f(k, s + 1, y);
		else f(k, s, y + 1);
		isVisit[i][j] = false;
	}
}

int main(void) {

	for (int i = 1; i <= 5; i++) {
		scanf("%s", &map[i][1]);
		for (int j = 1; j <= 5; j++) {
			v.push_back({ i, j });
		}
	}

	f(-1, 0, 0);

	printf("%d", ans);

	return 0;
}