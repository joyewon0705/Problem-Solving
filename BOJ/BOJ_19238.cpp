#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 22
typedef pair<int, int> P;
typedef pair<int, P> PP;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, f, r, c, x, y;
bool isVisit[N][N], chk[N * N];
int map[N][N];
vector<P> st, ed;

int getDistance(P a, P b) {
	queue<PP> q;

	memset(isVisit, false, sizeof(isVisit));
	q.push({ 0, a });
	while (!q.empty()) {
		int cnt = q.front().first;
		P cur = q.front().second;
		q.pop();

		if (cur.first == b.first && cur.second == b.second) return cnt;
		if (isVisit[cur.first][cur.second]) continue;
		isVisit[cur.first][cur.second] = true;

		for (int k = 0; k < 4; k++) {
			int nx = cur.first + dx[k];
			int ny = cur.second + dy[k];

			if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
			if (map[nx][ny]) continue;
			q.push({ cnt + 1, { nx, ny } });
		}
	}
	return INF;
}

P getNext() {
	int no, dist, x, y;

	no = x = y = -1;
	dist = INF;
	for (int i = 0; i < m; i++) {
		if (chk[i]) continue;
		int t = getDistance({ r, c }, st[i]);
		if (f < t) continue;
		if (dist > t ||
			(dist == t && (x > st[i].first || (x == st[i].first && y > st[i].second)))) {
			no = i;
			dist = t;
			x = st[i].first;
			y = st[i].second;
		}
	}
	return { no, dist };
}

int main(void) {

	scanf("%d %d %d", &n, &m, &f);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d", &r, &c);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		st.push_back({ x, y });
		scanf("%d %d", &x, &y);
		ed.push_back({ x, y });
	}

	int cnt = m;
	while (cnt--) {
		P next = getNext();
		if (next.first < 0) { f = -1; break; }
		chk[next.first] = true;

		int dist = getDistance(st[next.first], ed[next.first]);
		f -= next.second + dist;
		if (f < 0) { f = -1; break; }

		r = ed[next.first].first; c = ed[next.first].second;
		f += 2 * dist;
	}

	printf("%d", f);

	return 0;
}