#include <iostream>
#include <vector>
using namespace std;

#define N 22
#define M 111
typedef pair<int, int> P;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n, x, y, d, g, ans;
bool chk[M][M];
vector<P> v[N], cd;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		v[i].push_back({ x, y });
		v[i].push_back({ x + dx[d], y + dy[d] });
		for (int j = 0; j < g; j++) {
			int tmp = v[i].size() - 1;
			int a = v[i][tmp].first;
			int b = v[i][tmp].second;
			for (int k = tmp - 1; k > - 1; k--) {
				int x = a + b - v[i][k].second;
				int y = b + v[i][k].first - a;
				v[i].push_back({ x, y });
			}
		}

		for (P cur : v[i]) {
			if (chk[cur.first][cur.second]) continue;
			chk[cur.first][cur.second] = true;
			cd.push_back({ cur.first, cur.second });
		}
	}
	
	for (P cur : cd) {
		int i = cur.first;
		int j = cur.second;
		if (chk[i][j] && chk[i + 1][j] && chk[i][j + 1] && chk[i + 1][j + 1]) ans++;	
	}

	printf("%d", ans);

	return 0;
}