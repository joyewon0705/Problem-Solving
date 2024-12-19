#include <iostream>

#define N 13
#define K 11

typedef struct _horse {
	int x, y, dir, upper, lower;
}_horse;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

bool chk = true;
int n, k, turn;
int board[N][N];
_horse horses[K];

int reverseDirection(int dir) {
	switch (dir) {
	case 1: return 2;
	case 2: return 1;
	case 3: return 4;
	case 4: return 3;
	}
}

void reverseOrder(int cur, int bottom, int top) {

	if (horses[cur].upper == cur) {
		if (bottom != top) {
			horses[bottom].upper = cur;
			horses[cur].upper = bottom;
		}
	}
	else reverseOrder(horses[cur].upper, bottom, top);

	int tmp = horses[cur].lower;
	horses[cur].lower = horses[cur].upper;
	horses[cur].upper = tmp;
	
	if (cur == top) horses[cur].upper = top;
}

int getTop(int cur, int x, int y) {

	horses[cur].x = x;
	horses[cur].y = y;
	if (horses[cur].upper == cur) return cur;
	else return getTop(horses[cur].upper, x, y);
}

int countLower(int cur) {

	if (horses[cur].lower == cur) return 1;
	else return countLower(horses[cur].lower) + 1;
}

int countUpper(int cur) {

	if (horses[cur].upper == cur) return 1;
	else return countUpper(horses[cur].upper) + 1;
}

int count(int cur) {
	int ret = countLower(cur);
	if (horses[cur].upper != cur) ret += countUpper(horses[cur].upper);
	return ret;
}

void move(int cur, int x, int y) {

	if (horses[cur].lower != cur) {
		horses[horses[cur].lower].upper = horses[cur].lower;
		horses[cur].lower = cur;
	}
	for (int i = 1; i <= k; i++) {
		if (i == cur) continue;
		if (horses[i].x == x && horses[i].y == y) {
			int top = getTop(i, x, y);
			horses[top].upper = cur;
			horses[cur].lower = top;
			break;
		}
	}
	getTop(cur, x, y);

	if (count(cur) >= 4) chk = false;
}

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &horses[i].x, &horses[i].y, &horses[i].dir);
		horses[i].upper = horses[i].lower = i;
	}

	while (chk) {

		if (++turn > 1000) {
			turn = -1;
			break;
		}

		for (int i = 1; i <= k; i++) {
			int nx = horses[i].x + dx[horses[i].dir];
			int ny = horses[i].y + dy[horses[i].dir];

			if (board[nx][ny] == 2 || nx < 1 || n < nx || ny < 1 || n < ny) {
				horses[i].dir = reverseDirection(horses[i].dir);
				nx = horses[i].x + dx[horses[i].dir];
				ny = horses[i].y + dy[horses[i].dir];
				if (board[nx][ny] == 2 || nx < 1 || n < nx || ny < 1 || n < ny) continue;
			}
			if (board[nx][ny] == 1) {
				move(i, nx, ny);
				reverseOrder(i, horses[i].lower, i);
			}
			else move(i, nx, ny);
		}
	}

	printf("%d", turn);

	return 0;
}