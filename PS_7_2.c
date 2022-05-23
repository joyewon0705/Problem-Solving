#pragma warning(disable:4996)
#include <stdio.h>

#define N 1010

int n, m, num;
int w[N][N], d[N][N] = { 0 }, set[N * N / 2];
int getset(int x, int y, int num, int dir);
int search(int x, int y, int* counted, int dir);

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			if (getchar() == '1') w[i][j] = 1;
			else w[i][j] = 0;
		}
	}

	num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j]) {
				int counted[4] = { 0 };
				w[i][j] += search(i - 1, j, counted, 0);
				w[i][j] += search(i + 1, j, counted, 1);
				w[i][j] += search(i, j - 1, counted, 2);
				w[i][j] += search(i, j + 1, counted, 3);
			}
			printf("%d", (w[i][j] % 10));
		}
		printf("\n");
	}

	return 0;
}

int getset(int x, int y, int num, int dir) {
	int cnt = 1;

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y] || d[x][y]) return 0;

	d[x][y] = num;
	// 1: up, 2: down, 3: left, 4:right
	if (dir != 1) cnt += getset(x - 1, y, num, 2);
	if (dir != 2) cnt += getset(x + 1, y, num, 1);
	if (dir != 3) cnt += getset(x, y - 1, num, 4);
	if (dir != 4) cnt += getset(x, y + 1, num, 3);
	return cnt;
}

int search(int x, int y, int* counted, int dir) {

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y]) return 0;
	if (d[x][y] == 0) {
		set[num] = getset(x, y, num, 0);
		num++;
	}
	else {
		for (int i = 0; i < dir; i++)
			if (counted[i] == d[x][y]) return 0;
	}

	counted[dir] = d[x][y];
	return set[d[x][y]];
}

/*
#include <stdio.h>

#define N 1010

int n, m, num, counted;
char buf[N];
_Bool w[N][N];
int d[N][N], set[N * N];
typedef enum direction {
	Up, Down, Left, Right, Inplace
} direction;
int cnt_set(int x, int y, int num, direction before);
int search(int x, int y);

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			if (buf[j] == '1') w[i][j] = 1;
			else w[i][j] = 0;
		}
	}

	num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j] || d[i][j]) continue;
			set[num] = cnt_set(i, j, num, Inplace);
			num++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j]) {
				// num은 최대 1000 * 1000 / 2인데 그걸 비트 연산하다니..
				counted = 1 << num;
				d[i][j] = 1;
				d[i][j] += search(i - 1, j);
				d[i][j] += search(i + 1, j);
				d[i][j] += search(i, j - 1);
				d[i][j] += search(i, j + 1);
				printf("%d", (d[i][j] % 10));
			}
			else printf("%d", 0);
		}
		printf("\n");
	}

	return 0;
}

int cnt_set(int x, int y, int num, direction before) {
	int cnt = 1;

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y] || d[x][y]) return 0;

	d[x][y] = num;
	if (before != Up) cnt += cnt_set(x - 1, y, num, Down);
	if (before != Down) cnt += cnt_set(x + 1, y, num, Up);
	if (before != Left) cnt += cnt_set(x, y - 1, num, Right);
	if (before != Right) cnt += cnt_set(x, y + 1, num, Left);
	return cnt;
}

int search(int x, int y) {

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y]) return 0;
	if (counted & (1 << d[x][y])) return 0;

	counted = counted | (1 << d[x][y]);
	return set[d[x][y]];
}
*/

/*
#include <stdio.h>

#define N 1010

int n, m, num, counted;
char buf[N];
_Bool w[N][N];
int d[N][N], set[N * N];
int cnt_set(int x, int y, int num, int direction);
int search(int x, int y);

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			if (buf[j] == '1') w[i][j] = 1;
			else w[i][j] = 0;
		}
	}

	num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j] || d[i][j]) continue;
			set[num] = cnt_set(i, j, num, 0);
			num++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j]) {
				counted = 1 << num;
				d[i][j] = 1;
				d[i][j] += search(i - 1, j);
				d[i][j] += search(i + 1, j);
				d[i][j] += search(i, j - 1);
				d[i][j] += search(i, j + 1);
				printf("%d", (d[i][j] % 10));
			}
			else printf("0");
		}
		printf("\n");
	}

	return 0;
}

int cnt_set(int x, int y, int num, int direction) {
	int cnt = 1;

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y] || d[x][y]) return 0;

	d[x][y] = num;
	if (direction != 1) cnt += cnt_set(x - 1, y, num, 2);
	if (direction != 2) cnt += cnt_set(x + 1, y, num, 1);
	if (direction != 3) cnt += cnt_set(x, y - 1, num, 4);
	if (direction != 4) cnt += cnt_set(x, y + 1, num, 3);
	return cnt;
}

int search(int x, int y) {

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y]) return 0;
	if (counted & (1 << d[x][y])) return 0;

	counted = counted | (1 << d[x][y]);
	return set[d[x][y]];
}
*/

/*
#include <stdio.h>

#define N 1010

int n, m;
_Bool w[N][N];
int d[N][N] = { 0 };
int search(int x, int y);

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			if (getchar() == '1') w[i][j] = 1;
			else w[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (w[i][j]) {
				d[i][j] = 1;
				d[i][j] += search(i - 1, j);
				d[i][j] += search(i + 1, j);
				d[i][j] += search(i, j - 1);
				d[i][j] += search(i, j + 1);
				printf("%d", (d[i][j] % 10));
			}
			else printf("0");
		}
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", d[i][j]);
		}
		printf("\n");
	}


	return 0;
}

int search(int x, int y) {

	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (w[x][y]) return 0;
	if (d[x][y]) return d[x][y];

	d[x][y] = 1;
	//if (!w[x - 1][y]) d[x][y] += search(x - 1, y);
	if (!w[x + 1][y]) d[x][y] += search(x + 1, y);
	//if (!w[x][y - 1]) d[x][y] += search(x, y - 1);
	if (!w[x][y + 1]) d[x][y] += search(x, y + 1);

	return d[x][y];
}
*/