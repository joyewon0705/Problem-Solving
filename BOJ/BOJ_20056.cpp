#include <iostream>
#include <cstring>
using namespace std;

#define N 52
typedef struct _info { long long cnt, m, s, d; }_info;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

long long n, t, k, r, c, m, s, d, ans;
_info map[N][N], tmap[N][N];

int getPos(long long x, long long d, long long s) {
	int nx = x + d * s;
	while (nx < 1) nx += n;
	while (nx > n) nx -= n;
	return nx;
}

void merge(long long r, long long c, long long m, long long s, long long d) {

	map[r][c].m += m;
	map[r][c].s += s;
	if (map[r][c].cnt) {
		if (map[r][c].d > -1 && map[r][c].d % 2 != d % 2) map[r][c].d = -1;
	}
	else {
		map[r][c].d = d;
	}
	map[r][c].cnt += 1;
}

int main(void) {

	scanf("%d %d %d", &n, &t, &k);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		merge(r, c, m, s, d);
	}

	while (k--) {
		memcpy(tmap, map, sizeof(map));
		memset(map, 0, sizeof(map));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tmap[i][j].cnt > 1) {
					tmap[i][j].m /= 5;
					if (tmap[i][j].m == 0) continue;
					tmap[i][j].s /= tmap[i][j].cnt;
					for (int nd = tmap[i][j].d < 0 ? 1 : 0; nd < 8; nd += 2) {
						int nx = getPos(i, dx[nd], tmap[i][j].s);
						int ny = getPos(j, dy[nd], tmap[i][j].s);

						merge(nx, ny, tmap[i][j].m, tmap[i][j].s, nd);
					}
				}
				else if (tmap[i][j].cnt == 1) {
					int nx = getPos(i, dx[tmap[i][j].d], tmap[i][j].s);
					int ny = getPos(j, dy[tmap[i][j].d], tmap[i][j].s);

					merge(nx, ny, tmap[i][j].m, tmap[i][j].s, tmap[i][j].d);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].cnt > 1) {
				map[i][j].m /= 5;
				if (map[i][j].m == 0) continue;
				ans += 4 * map[i][j].m;
			}
			else ans += map[i][j].m;
		}
	}
	printf("%lld", ans);

	return 0;
}