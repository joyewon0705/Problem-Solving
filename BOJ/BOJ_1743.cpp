#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 101
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, k, r, c, ans;
bool map[N][N];
vector<P> v;
queue<P> q;

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &r, &c);
		v.push_back({ r, c });
		map[r][c] = true;
	}

	for (int i = 0; i < k; i++) {
		int r = v[i].first;
		int c = v[i].second;

		if (!map[r][c]) continue;

		int size = 0;
		q.push({ r, c });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (!map[x][y]) continue;
			map[x][y] = false;
			size++;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
				
				q.push({ nx, ny });
			}
		}
		if (ans < size) ans = size;
	}

	printf("%d", ans);

	return 0;
}