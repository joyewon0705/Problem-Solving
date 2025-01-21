#include <iostream>
#include <vector>
using namespace std;

#define N 101

typedef pair<int, int> P;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n, x, y, d, g, ans;
bool map[N][N];

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		vector <P> v = { { x, y }, { x + dx[d], y + dy[d] } };
		map[x][y] = true;
		map[x + dx[d]][y + dy[d]] = true;
		for (int j = 0; j < g; j++) {
			int a = v[v.size() - 1].first;
			int b = v[v.size() - 1].second;
			for (int k = v.size() - 2; k >= 0; k--) {
				x = -v[k].second + a + b;
				y = v[k].first - a + b;
				map[x][y] = true;
				v.push_back({ x, y });
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) ans++;
		}
	}
	printf("%d", ans);

	return 0;
}