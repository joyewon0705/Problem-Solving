#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define N 9

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, cnt, ret, ans;
bool map[N][N], tmap[N][N];
vector<P> v, viruses;

void sf(int x, int y) {

	if (tmap[x][y]) return;

	ret--;
	tmap[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
		sf(nx, ny);
	}
}

int f() {

	ret = cnt - 3;
	memcpy(tmap, map, sizeof(map));
	for (P virus : viruses) {
		ret++;
		sf(virus.first, virus.second);
	}
	
	return ret;
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &ret);
			if (ret == 0) v.push_back({ i, j });
			else if (ret == 1) map[i][j] = true;
			else viruses.push_back({ i, j });
		}
	}

	cnt = v.size();
	for (int i = 0; i < cnt; i++) {
		map[v[i].first][v[i].second] = 1;
		for (int j = i + 1; j < cnt; j++) {
			map[v[j].first][v[j].second] = 1;
			for (int k = j + 1; k < cnt; k++) {
				map[v[k].first][v[k].second] = 1;
				if (i == 0 && j == 4 && k == 15)
					i = i;
				ans = max(ans, f());
				map[v[k].first][v[k].second] = 0;
			}
			map[v[j].first][v[j].second] = 0;
		}
		map[v[i].first][v[i].second] = 0;
	}

	printf("%d", ans);

	return 0;
}