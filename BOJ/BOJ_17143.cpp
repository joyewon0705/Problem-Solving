#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define N 101

typedef pair<int, int> P;
typedef struct _shark { int x, y, s, d, z; } _shark;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

int r, c, m, x, y, s, d, z, chk, ans;
int map[N][N];
vector<_shark> sharks = { { 0, 0, 0, 0, 0 } };

int main(void) {

	scanf("%d %d %d", &r, &c, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		sharks.push_back({ x, y, s, d, z });
		map[x][y] = i;
	}

	for (int j = 1; j <= c; j++) {
		chk = map[0][0];

		for (int i = 1; i <= r; i++) {
			if (chk = map[i][j]) {
				ans += sharks[chk].z;
				sharks[chk] = { -1, -1, -1, -1, -1 };
				break;
			}
		}
		memset(map, 0, sizeof(map));

		for (int k = 1; k <= m; k++) {
			_shark shk = sharks[k];
			if (shk.x < 0) continue;

			int nx = shk.x;
			int ny = shk.y;
			int ns = shk.s;
			int nd = shk.d;

			while ((chk = nx + dx[nd] * ns) < 1 || chk > r) {
				if (chk < 1) {
					ns -= nx - 1;
					nx = 1;
				}
				else if (chk > r) {
					ns -= r - nx;
					nx = r;
				}
				nd = nd > 1 ? 1 : 2;
			}
			nx = chk;
			while ((chk = ny + dy[nd] * ns) < 1 || chk > c) {
				if (chk < 1) {
					ns -= ny - 1;
					ny = 1;
				}
				else if (chk > c) {
					ns -= c - ny;
					ny = c;
				}
				nd = nd > 3 ? 3 : 4;
			}
			ny = chk;

			if (chk = map[nx][ny]) {
				if (shk.z > sharks[chk].z) {
					map[nx][ny] = k;
					sharks[chk] = { -1, -1, -1, -1, -1 };
					sharks[k] = { nx, ny, shk.s, nd, shk.z };
				}
				else {
					sharks[k] = { -1, -1, -1, -1, -1 };
				}
			}
			else {
				map[nx][ny] = k;
				sharks[k] = { nx, ny, shk.s, nd, shk.z };
			}
		}
	}

	printf("%d", ans);

	return 0;
}