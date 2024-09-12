#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define N 22

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, a, b, c, d, score;
bool isVisit[N][N];
int board[N][N], nboard[N][N];
stack<P> st;

P bfs(int x, int y, int color) {
	P ret = { 0, 0 };

	if (board[x][y] && board[x][y] != color) return ret;
	if (isVisit[x][y]) return ret;

	isVisit[x][y] = true;
	if (board[x][y] == 0) st.push({ x, y });

	ret.first = 1;
	if (board[x][y] == 0) ret.second = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || n < ny) continue;

		P tmp = bfs(nx, ny, color);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}
	return ret;
}

void bfse(int x, int y, int color) {

	if (board[x][y] && board[x][y] != color) return;

	board[x][y] = -2;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || n < ny) continue;

		bfse(nx, ny, color);
	}
}

void setGravity() {

	for (int i = n - 1; i; i--) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] < 0) continue;
			for (int k = i + 1; k <= n; k++) {
				if (board[k][j] < -1) {
					board[k][j] = board[k - 1][j];
					board[k - 1][j] = -2;
				}
				else break;
			}
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	while (true) {
		// 1단계
		memset(isVisit, false, sizeof(isVisit));
		a = b = c = d = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] <= 0) continue;
				P tmp = bfs(i, j, board[i][j]);
				if (tmp.first < 2) continue;
				if (tmp.first > c || (tmp.first == c && tmp.second >= d)) {
					a = i; b = j; c = tmp.first; d = tmp.second;
				}
				while (!st.empty()) {
					P b = st.top();
					st.pop();
					isVisit[b.first][b.second] = false;
				}
			}
		}
		if (!a) break;

		// 2단계
		bfse(a, b, board[a][b]);
		score += c * c;

		// 3단계
		setGravity();

		// 4단계
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nboard[n + 1 - i][j] = board[j][i];
			}
		}
		memcpy(board, nboard, sizeof(board));

		// 5단계
		setGravity();
	}

	printf("%d", score);

	return 0;
}