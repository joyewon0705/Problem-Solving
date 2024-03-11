#include <iostream>
#include <cstring>

#define N 101
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, k, s, ans;
bool isVisit[N][N][N];
char A[N][N], word[N];
int dp[N][N][N];

int f(int x, int y, int cur) {

	if (A[x][y] != word[cur]) return 0;
	if (isVisit[x][y][cur]) return dp[x][y][cur];
	if (cur == s - 1) return dp[x][y][cur] = 1;

	isVisit[x][y][cur] = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			dp[x][y][cur] += f(nx, ny, cur + 1);
		}
	}
	return dp[x][y][cur];
}

int main(void) {

	scanf("%d %d %d\n", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s\n", &A[i][1]);
	}
	scanf("%s", word);
	s = strlen(word);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans += f(i, j, 0);
		}
	}

	printf("%d", ans);

	return 0;
}