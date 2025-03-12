#include <iostream>
#include <vector>
using namespace std;

#define N 50

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

int n, m, c, d, s, ans;
int map[N][N];
vector<int> v;

void init() {
	int x, y, d, no = 1;

	x = y = c = (n + 1) / 2;
	map[c][c] = -1;
	d = 1;
	while (x != 1 || y != 1) {
		int nd = d == 1 ? 3 : d == 2 ? 4 : d == 3 ? 2 : 1;	// 3 2 4 1
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if (map[nx][ny]) {
			x = x + dx[d];
			y = y + dy[d];
		}
		else {
			d = nd;
			x = nx;
			y = ny;
		}
		map[x][y] = no++;
	}
	map[c][c] = 0;
	v = vector<int>(n * n, 0);
}
 
int main(void) {

	scanf("%d %d", &n, &m); 
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &v[map[i][j]]);
		}
	}
	
	while (m--) {
		scanf("%d %d", &d, &s);

		for (int i = s; i; i--) {
			int nx = c + dx[d] * i;
			int ny = c + dy[d] * i;

			if (map[nx][ny] >= v.size()) continue;
			v.erase(v.begin() + map[nx][ny]);
		}

		bool chk = true; 
		while (chk) {
			int cnt = 1;
			chk = false;
			for (int i = v.size() - 2; i >= 0; i--) {
				if (v[i] == v[i + 1]) cnt++;
				else {
					if (cnt >= 4) {
						chk = true;
						ans += v[i + 1] * cnt;
						while (cnt) {
							v.erase(v.begin() + i + cnt--);
						}
					}
					cnt = 1;
				}
			}
		}

		int cnt = 1;
		vector<int> nv = { 0 };
		v.push_back(0);
		for (int i = 2; i < v.size(); i++) {
			if (v[i - 1] == v[i]) cnt++;
			else {
				if (v[i - 1]) {
					nv.push_back(cnt);
					nv.push_back(v[i - 1]);
				}
				if (nv.size() >= n * n) break;
				cnt = 1;
			}
		}
		v = nv;
	}

	printf("%d", ans);

	return 0;
}