#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N 101
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, k, r, a, b, c, d, ans;
bool paths[N][N][4], isVisit[N][N], chk[N][N];
int map[N][N];
vector<P> cows;
queue<P> q;

void setPath(int a, int b, int c, int d) {
	c -= a;
	d -= b;

	for (int i = 0; i < 4; i++) {
		if (dx[i] == c && dy[i] == d) {
			paths[a][b][i] = true;
			break;
		}
	}
}

int main(void) {

	scanf("%d %d %d", &n, &k, &r);
	for (int i = 0; i < r; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		setPath(a, b, c, d);
		setPath(c, d, a, b);
	}
	cows.push_back({ 0, 0 });
	for (int i = 1; i <= k; i++) {
		scanf("%d %d", &a, &b);
		cows.push_back({ a, b });
		map[a][b] = i;
	}

	for (int i = 1; i <= k; i++) {
		memset(isVisit, false, sizeof(isVisit));

		q.push(cows[i]);
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (isVisit[x][y]) continue;
			isVisit[x][y] = true;

			if (map[x][y]) chk[i][map[x][y]] = true;
			
			for (int k = 0; k < 4; k++) {
				if (paths[x][y][k]) continue;

				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;

				q.push({ nx, ny });
			}
		}

		map[cows[i].first][cows[i].second] = 0;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j++) {
			if (chk[i][j]) continue;
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}