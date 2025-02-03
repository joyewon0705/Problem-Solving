#include <iostream>
#include <cstring>
using namespace std;

#define N 101

typedef struct _info { int x, y, s, d, z; }_info;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

int r, c, m, x, y, s, d, z, ans;
int map[N][N];
_info sharks[N * N];

int main(void) {

	scanf("%d %d %d", &r, &c, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		map[x][y] = i;
		sharks[i] = { x, y, s % (2 * (d > 2 ? c - 1 : r - 1)), d, z};
	}

	for (int j = 1; j <= c; j++) {
		for (int i = 1; i <= r; i++) {
			if (map[i][j]) {
				ans += sharks[map[i][j]].z;
				sharks[map[i][j]].x = 0;
				map[i][j] = 0;
				break;
			}
		}

		memset(map, 0, sizeof(map));
		for (int i = 1; i <= m; i++) {
			if (sharks[i].x == 0) continue;

			x = sharks[i].x;
			y = sharks[i].y;
			s = sharks[i].s;
			d = sharks[i].d;

			x += s * dx[d];
			y += s * dy[d];

			while (x < 1 || r < x || y < 1 || c < y) {
				d = d % 2 ? d + 1 : d - 1;
				if (x < 1) x = 2 - x;
				else if (r < x) x = r - (x - r);
				else if (y < 1) y = 2 - y;
				else if (c < y) y = c - (y - c);
			}
			sharks[i].x = x;
			sharks[i].y = y;
			sharks[i].d = d;

			if (map[x][y]) {
				if (sharks[i].z > sharks[map[x][y]].z) {
					sharks[map[x][y]].x = 0;
					map[x][y] = i;
				}
				else {
					sharks[i].x = 0;
				}
			}
			else map[x][y] = i;
		}

	}

	printf("%d", ans);

	return 0;
}