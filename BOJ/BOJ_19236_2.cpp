#include <iostream>
#include <cstring>
using namespace std;

typedef struct _info { int x, y, d; }_info;
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int a, b, ans;
int map[5][5];
_info fishes[17];

void f(int x, int y, int d, int val) {

	val += map[x][y];
	d = fishes[map[x][y]].d;
	map[x][y] = -1;

	for (int i = 1; i <= 16; i++) {
		int x = fishes[i].x;
		int y = fishes[i].y;
		int d = fishes[i].d;
		
		if (map[x][y] != i) continue;

		for (int k = 0; k < 8; k++) {
			int nd = (d + k - 1) % 8 + 1;
			int nx = x + dx[nd];
			int ny = y + dy[nd];

			if (nx < 1 || 4 < nx || ny < 1 || 4 < ny) continue;
			if (map[nx][ny] < 0) continue;

			map[x][y] = map[nx][ny];
			map[nx][ny] = i;
			fishes[map[x][y]] = { x, y, fishes[map[x][y]].d };
			fishes[i] = { nx, ny, nd };
			break;
		}
	}

	map[x][y] = 0;
	int mmap[5][5];
	_info ffishes[17];
	memcpy(mmap, map, sizeof(map));
	memcpy(ffishes, fishes, sizeof(fishes));
	while (true) {
		x += dx[d];
		y += dy[d];

		if (x < 1 || 4 < x || y < 1 || 4 < y) break;
		if (map[x][y] == 0) continue;

		f(x, y, d, val);
		memcpy(map, mmap, sizeof(map));
		memcpy(fishes, ffishes, sizeof(fishes));
	}

	if (ans < val) 
		ans = val;
}

int main(void) {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%d %d", &a, &b);
			map[i][j] = a;
			fishes[a] = { i, j, b };
		}
	}

	f(1, 1, 0, 0);

	printf("%d", ans);


	return 0;
}