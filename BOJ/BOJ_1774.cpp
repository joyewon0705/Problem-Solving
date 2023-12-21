#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<10
#define N 1010
typedef pair<double, int> P;

int n, m, x, y;
double ans;
bool chk[N];
double b[N][N];
P cd[N];
priority_queue<P, vector<P>, greater<P>> pq;

double getDistance(P a, P b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		cd[i] = { x, y };
		for (int j = 1; j <= n; j++) b[i][j] = INF;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		b[x][y] = b[y][x] = 0;
	}

	pq.push({ 0, 1 });
	while (!pq.empty()) {
		double val = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (chk[cur]) continue;
		chk[cur] = true;
		ans += val;

		for (int i = 1; i <= n; i++) {
			if (chk[i]) continue;
			if (b[cur][i] >= INF) b[cur][i] = getDistance(cd[cur], cd[i]);
			pq.push({ b[cur][i], i });
		}
	}

	printf("%.2f", round(100 * ans) / 100);

	return 0;
}