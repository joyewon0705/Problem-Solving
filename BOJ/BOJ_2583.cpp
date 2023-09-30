#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 101
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int m, n, k, a, b, c, d;
bool map[N][N];
vector<int> v;
queue<P> q;

int main(void) {

	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = a; i < c; i++)
			for (int j = b; j < d; j++)
				map[i][j] = true;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) continue;
			int cnt = 0;

			q.push({ i, j });
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (map[x][y]) continue;
				map[x][y] = true;
				cnt++;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
					q.push({ nx, ny });
				}
			}

			v.push_back(cnt);
		}
	}

	printf("%d\n", v.size());
	sort(v.begin(), v.end());
	for (int ans : v) printf("%d ", ans);

	return 0;
}