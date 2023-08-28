#include <iostream>
#include <cstring>

typedef struct _info { int x, y, d; }_info;
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int a, b, ans;
bool chk[17];
int map[5][5];
_info info[17];

void dfs(_info shark, int sum) {

	int tmp = map[shark.x][shark.y];
	map[shark.x][shark.y] = 0;
	chk[tmp] = true;
	sum += tmp;
	int nd = info[tmp].d;
	if (ans < sum) 
		ans = sum;

	for (int i = 1; i <= 16; i++) {
		if (chk[i]) continue;

		for (int k = 0; k < 8; k++) {
			int nd = info[i].d + k;
			if (nd > 8) nd -= 8;
			int nx = info[i].x + dx[nd];
			int ny = info[i].y + dy[nd];

			if (nx == shark.x && ny == shark.y) continue;
			if (nx < 1 || 4 < nx || ny < 1 || 4 < ny) continue;
			
			if (map[nx][ny]) {
				info[map[nx][ny]].x = info[i].x;
				info[map[nx][ny]].y = info[i].y;
				map[info[i].x][info[i].y] = map[nx][ny];
			}
			else map[info[i].x][info[i].y] = 0;
			map[nx][ny] = i;
			info[i] = { nx, ny, nd };
			break;
		}
	}

	for (int i = 1; i < 4; i++) {
		int nx = shark.x + dx[nd] * i;
		int ny = shark.y + dy[nd] * i;

		if (map[nx][ny] == 0) continue;
		if (nx < 1 || 4 < nx || ny < 1 || 4 < ny) break;

		bool save_chk[17];
		int save_map[5][5];
		_info save_info[17];
		memcpy(save_chk, chk, sizeof(chk));
		memcpy(save_map, map, sizeof(map));
		memcpy(save_info, info, sizeof(info));

		dfs({ nx, ny, nd }, sum);

		memcpy(chk, save_chk, sizeof(chk));
		memcpy(map, save_map, sizeof(map));
		memcpy(info, save_info, sizeof(info));
	}
}

int main(void) {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%d %d", &a, &b);
			info[a] = { i, j, b };
			map[i][j] = a;
		}
	}

	dfs({ 1, 1, 0 }, 0);

	printf("%d", ans);

	return 0;
}