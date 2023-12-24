#include <iostream>

#define N 505
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

char ch;
int n, m, ans;
bool isEscape[N][N], isVisit[N][N];
int map[N][N];

bool dfs(int x, int y) {

	if (x < 1 || n < x || y < 1 || m < y) return true;
	if (isVisit[x][y]) return isEscape[x][y];
	isVisit[x][y] = true;

	int d = map[x][y];
	return isEscape[x][y] = dfs(x + dx[d], y + dy[d]);
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			ch = getchar();
			if (ch == 'U') map[i][j] = 0;
			else if (ch == 'R') map[i][j] = 1;
			else if (ch == 'D') map[i][j] = 2;
			else if (ch == 'L') map[i][j] = 3;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dfs(i, j)) ans++;
		}
	}

	printf("%d", ans);

	return 0;
}