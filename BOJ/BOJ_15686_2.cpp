#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF 1<<30
#define N 51
#define M 14

typedef pair<int, int> P;

int n, m, v, ans = INF;
int dist[2 * N][M], d[2 * N];
bool chk[M];
vector<P> v1, v2;

void f(int cur, int cnt) {

	if (cnt >= m) {
		for (int i = 0; i < v1.size(); i++) d[i] = INF;

		for (int j = 0; j < v2.size(); j++) {
			if (!chk[j]) continue;
			for (int i = 0; i < v1.size(); i++) {
				d[i] = min(d[i], dist[i][j]);
			}
		}

		v = 0;
		for (int i = 0; i < v1.size(); i++) v += d[i];

		ans = min(ans, v);
		return;
	}
	if (cur >= v2.size()) return;

	chk[cur] = true;
	f(cur + 1, cnt + 1);
	chk[cur] = false;
	f(cur + 1, cnt);
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &v);
			if (v == 1) v1.push_back({ i, j });
			else if (v == 2) v2.push_back({ i, j });
		}
	}

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			dist[i][j] = abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second);
		}
	}

	f(0, 0);

	printf("%d", ans);

	return 0;
}