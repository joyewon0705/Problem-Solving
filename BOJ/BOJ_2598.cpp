#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 55
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
typedef pair<int, int> P;

char ch;
int n, m, ans;
bool map[N][N], isVisit[N][N];
queue<pair<int, P>> q;

int getFarthest(int i, int j) {
	int ret = 0;
	q = queue<pair<int, P>>();
	memset(isVisit, false, sizeof(isVisit));

	q.push({ 0, { i, j } });
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (isVisit[x][y]) continue;
		isVisit[x][y] = true;

		if (ret < cnt) ret = cnt;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			if (map[nx][ny]) continue;
			if (isVisit[nx][ny]) continue;
			q.push({ cnt + 1, { nx, ny } });
		}
	}

	return ret;
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			if (ch == 'W') map[i][j] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == false) {
				int ret = getFarthest(i, j);
				if (ans < ret) ans = ret;
			}
		}
	}

	printf("%d", ans);

	return 0;
}