#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 22

typedef struct _info { int x, y, z; }_info;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int n, m, x, y, z, cnt, ans;
int map[N][N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				x = i; y = j;
				map[i][j] = 0;
			}
			else if (map[i][j] > 0) m++;
		}
	}

	z = 2;
	while (m) {
		bool isPossible = false;
		int i, j, k = INF;
		queue<_info> q;
		bool chk[N][N] = { false };
		
		q.push({ x, y, 0 });
		while (!q.empty()) {
			int a = q.front().x;
			int b = q.front().y;
			int c = q.front().z;
			q.pop();

			if (c > k) break;

			if (chk[a][b]) continue;
			chk[a][b] = true;

			if (map[a][b] > z) continue;
			if (map[a][b] && map[a][b] < z) {
				isPossible = true;
				if (k >= INF || a < i || (a == i && b < j)) {
					i = a; j = b; k = c;
				}
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int na = a + dx[k];
				int nb = b + dy[k];

				if (na < 1 || n < na || nb < 1 || n < nb) continue;
				q.push({ na, nb, c + 1 });
			}
		}

		if (isPossible) {
			map[i][j] = 0;
			m--; cnt++;
			ans += k;
			x = i; y = j;
		}
		else break;

		if (cnt == z) {
			cnt = 0;
			z++;
		}
	}

	printf("%d", ans);

	return 0;
}