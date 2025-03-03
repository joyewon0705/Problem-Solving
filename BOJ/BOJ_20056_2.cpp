#include <iostream>

#define N 55

typedef struct _fireball { int m, s, d; }_fireball;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n, t, k, r, c, m, s, d, ans;
_fireball map[2][N][N];
int cnt[2][N][N];

int getCD(int x) {
    return (x % n + n - 1) % n + 1;
}

void move(int r, int c, int m, int s, int d) {

	if (cnt[k % 2][r][c]) {
		map[k % 2][r][c].m += m;
		map[k % 2][r][c].s += s;
		if (map[k % 2][r][c].d > -1 && map[k % 2][r][c].d % 2 != d % 2)
			map[k % 2][r][c].d = -1;
	}
	else map[k % 2][r][c] = { m, s, d };
	cnt[k % 2][r][c]++;
}

int main(void) {

	scanf("%d %d %d", &n, &t, &k);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		map[k % 2][r][c] = { m, s, d };
		cnt[k % 2][r][c]++;
	}

	while (k--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt[(k + 1) % 2][i][j] > 1) {
					_fireball cur = map[(k + 1) % 2][i][j];
					int nm = cur.m / 5;
					if (nm == 0) continue;
					int ns = cur.s / cnt[(k + 1) % 2][i][j];
					int nd = cur.d < 0 ? 1 : 0;
					for (; nd < 8; nd += 2) {
						int nx = getCD(i + dx[nd] * ns);
						int ny = getCD(j + dy[nd] * ns);

						move(nx, ny, nm, ns, nd);
					}
				}
				else if (cnt[(k + 1) % 2][i][j] == 1) {
					_fireball cur = map[(k + 1) % 2][i][j];
					int nx = getCD(i + dx[cur.d] * cur.s);
					int ny = getCD(j + dy[cur.d] * cur.s);

					move(nx, ny, cur.m, cur.s, cur.d);
				}
			}
		}
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                map[(k + 1) % 2][i][j] = { 0, 0, 0 };
                cnt[(k + 1) % 2][i][j] = 0;
            }
        }
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt[0][i][j] > 1) ans += (map[0][i][j].m / 5) * 4;
			else ans += map[0][i][j].m;
		}
	}
	printf("%d", ans);

	return 0;
}