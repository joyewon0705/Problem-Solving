#include <iostream>

#define N 10101
int dx[] = { -1, 0, 1 };

int r, c, ans;
char map[N][N];

bool f(int x, int y) {

	if (y == c - 1) return true;

	for (int k = 0; k < 3; k++) {
		int nx = x + dx[k];
		int ny = y + 1;

		if (nx < 0 || r <= nx) continue;
		if (map[nx][ny] == '.') {
			map[nx][ny] = 'o';
			if (f(nx, ny)) return true;
		}
	}
	return false;
}

int main(void) {

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < r; i++) {
		map[i][0] = 'o';
		if (f(i, 0)) ans++;
	}

	printf("%d", ans);

	return 0;
}