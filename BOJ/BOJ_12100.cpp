#include <iostream>
#include <cstring>
#include <cmath>

#define N 22

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, ans;
int board[N][N];
bool chk[N][N];

int setBlock(int k, int i, int j) {
	int x, y, nx, ny;

	x = i; y = j;
	while (true) {
		nx = x + dx[k];
		ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || n < ny) {
			break;
		}
		else if (board[nx][ny] == 0) {
			x = nx; y = ny;
		}
		else if (chk[nx][ny] || board[nx][ny] != board[i][j]) {
			break;
		}
		else {
			chk[nx][ny] = true;
			board[nx][ny] *= 2;
			board[i][j] = 0;
			return board[nx][ny];
		}
	}
	board[x][y] = board[i][j];
	if (x != i || y != j) board[i][j] = 0;
	return board[x][y];
}

int setBoard(int k) {
	int max, ret, x, y, nx, ny;

	max = 0;
	memset(chk, false, sizeof(chk));
	if (k % 2) {
		for (int i = n; i; i--) {
			for (int j = n; j; j--) {
				if (board[i][j]) {
					ret = setBlock(k, i, j);
					if (max < ret) max = ret;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j]) {
					ret = setBlock(k, i, j);
					if (max < ret) max = ret;
				}
			}
		}
	}
	return max;
}

void dfs(int cnt) {
	int cur[N][N];

	if (cnt >= 5) return;

	memcpy(cur, board, sizeof(board));
	for (int k = 0; k < 4; k++) {
		int max = setBoard(k);
		dfs(cnt + 1);
		memcpy(board, cur, sizeof(board));
		if (ans < max) ans = max;
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
			if (ans < board[i][j]) ans = board[i][j];
		}
	}

	dfs(0);

	printf("%d", ans);

	return 0;
}