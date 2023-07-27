#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 1010
#define K 11
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int n, m, k;
bool map[N][N];
int cnt[N][N][K];
queue<pair<P, P>> q;

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int l = 0; l <= k; l++)
				cnt[i][j][l] = INF;
	for (int i = 1; i <= n; i++) {
		while (getchar() != '\n');
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			if (ch == '1') map[i][j] = true;
		}
	}

	q.push({ { 0, 1 }, { 1, 1 } });
	while (!q.empty()) {
		int chk = q.front().first.first;
		int val = q.front().first.second;
		P cur = q.front().second;
		q.pop();

		if (cnt[cur.first][cur.second][chk] <= val) continue;
		cnt[cur.first][cur.second][chk] = val++;

		if (map[cur.first][cur.second]) {
			if (chk > k) continue;
			else chk++;
		}
		if (cur.first == n && cur.second == m) {
			printf("%d", cnt[n][m][chk]);
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = cur.first + dx[k];
			int ny = cur.second + dy[k];

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			q.push({ { chk, val } , { nx, ny } });
		}
	}

	printf("-1");

	return 0;
}