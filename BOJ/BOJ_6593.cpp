#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 33
typedef struct _cd { int x, y, z; }_cd;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

char ch;
int l, r, c, ans;
bool isVisit[N][N][N];
_cd s, e;
queue<pair<int, _cd>> q;

int main(void) {

	while (true) {
		scanf("%d %d %d", &l, &r, &c);
		
		if (l == 0 && r == 0 && c == 0) break;

		ans = 0;
		memset(isVisit, false, sizeof(isVisit));
		q = queue<pair<int, _cd>>();

		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				getchar();
				for (int k = 1; k <= c; k++) {
					ch = getchar();
					if (ch == '#') isVisit[i][j][k] = true;
					else if (ch == 'S') s = { i, j, k };
					else if (ch == 'E') e = { i, j, k };
				}
			}
			getchar();
		}

		q.push({ 0, s });
		while (!q.empty()) {
			int cnt = q.front().first;
			_cd cur = q.front().second;
			q.pop();

			if (cur.x == e.x && cur.y == e.y && cur.z == e.z) {
				ans = cnt;
				break;
			}
			if (isVisit[cur.x][cur.y][cur.z]) continue;
			isVisit[cur.x][cur.y][cur.z] = true;

			for (int k = 0; k < 6; k++) {
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				int nz = cur.z + dz[k];

				if (nx < 1 || l < nx || ny < 1 || r < ny || nz < 1 || c < nz) continue;
				q.push({ cnt + 1, { nx, ny, nz } });
			}
		}

		if (ans) printf("Escaped in %d minute(s).\n", ans);
		else printf("Trapped!\n");
	}

	return  0;
}