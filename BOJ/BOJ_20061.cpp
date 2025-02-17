#include <iostream>

int n, t, x, y, ans, cnt;
bool board[2][6][4];

void erase(int c, int x) {
	for (int i = x; i; i--) {
		for (int j = 0; j < 4; j++) {
			board[c][i][j] = board[c][i - 1][j];
		}
	}
	for (int j = 0; j < 4; j++) {
		board[c][0][j] = false;
	}
}

bool check(int c, int x) {
	bool ret = true;
	for (int j = 0; j < 4; j++) {
		if (!board[c][x][j]) {
			ret = false;
			break;
		}
	}
	return ret;
}

void setBoard(int c, int t, int y) {
	int i = 2;

	if (t == 1) {
		for (; i < 6; i++) {
			if (board[c][i][y]) break;
		}
		i--;
		board[c][i][y] = true;
		if (check(c, i)) {
			erase(c, i); 
			ans++;
		}
		if (board[c][1][y]) erase(c, 5);
	}
	else if (t == 2) {
		for (; i < 6; i++) {
			if (board[c][i][y] || board[c][i][y + 1]) break;
		}
		i--;
		board[c][i][y] = board[c][i][y + 1] = true;
		if (check(c, i)) {
			erase(c, i); 
			ans++;
		}
		if (board[c][1][y]) erase(c, 5);
	}
	else if (t == 3) {
		for (; i < 6; i++) {
			if (board[c][i][y]) break;
		}
		i -= 2;
		board[c][i][y] = board[c][i + 1][y] = true;
		if (check(c, i)) {
			erase(c, i); 
			ans++;
		}
		if (check(c, i + 1)) {
			erase(c, i + 1); 
			ans++;
		}
		while (board[c][1][y]) erase(c, 5);
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &t, &x, &y);

		if (t == 1) {
			setBoard(0, 1, x);
			setBoard(1, 1, y);
		}
		else if (t == 2) {
			setBoard(0, 3, x);
			setBoard(1, 2, y);
		}
		else if (t == 3) {
			setBoard(0, 2, x);
			setBoard(1, 3, y);
		}
	}

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[0][i][j]) cnt++;
			if (board[1][i][j]) cnt++;
		}
	}
	printf("%d\n%d", ans, cnt);

	return 0;
}