#include <iostream>
#include <queue>
using namespace std;

#define N 101
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, x, y, a, b, cnt;
bool chk[N][N], isVisit[N][N];
vector<P> v[N][N];
queue<P> q;

int main(void) {

	scanf("%d %d ", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		v[x][y].push_back({ a, b });
	}

	chk[1][1] = true;
	cnt++;
	q.push({ 1, 1 });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		 
		if (isVisit[x][y]) continue;
		isVisit[x][y] = true;

		for (P room : v[x][y]) {
			a = room.first;
			b = room.second;
			
			if (chk[a][b]) continue;
			chk[a][b] = true;
			cnt++;

			for (int k = 0; k < 4; k++) {
				int nx = a + dx[k];
				int ny = b + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (isVisit[nx][ny]) q.push({ a, b });
			}
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
			if (chk[nx][ny]) q.push({ nx, ny });
		}
	}
	
	printf("%d", cnt);

	return 0;
}