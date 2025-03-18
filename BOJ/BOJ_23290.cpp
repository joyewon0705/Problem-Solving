#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define M 11

typedef pair<int, int> P;
typedef struct _info { int x, y, d; } _info;
int dx_f[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy_f[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx_s[] = { 0, -1, 0, 1, 0 };
int dy_s[] = { 0, 0, -1, 0, 1 };

int m, s, x, y, d;
int smell[5][5];
vector<P> movement;
queue<int> map[5][5];
queue<_info> fishes, copies;

void f(int x, int y, int cnt, vector<P> pos) {

	if (pos.size() == 3) {
		if (d < cnt) {
			d = cnt;
			movement = pos;
		}
		return;
	}

	for (int k = 1; k <= 4; k++) {

		int nx = x + dx_s[k];
		int ny = y + dy_s[k];

		if (nx < 1 || 4 < nx || ny < 1 || 4 < ny) continue;

		vector<P> npos = pos;
		npos.push_back({ nx, ny });
		if (map[nx][ny].size()) {
			bool chk = true;
			for (P cur : pos) {
				if (cur.first == nx && cur.second == ny) {
					f(nx, ny, cnt, npos);
					chk = false;
					continue;
				}
			}
			if (chk) f(nx, ny, cnt + map[nx][ny].size(), npos);
		}
		else f(nx, ny, cnt, npos);
	}
}

int main(void) {

	scanf("%d %d", &m, &s);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &d);
		fishes.push({ x, y, d });
	}
	scanf("%d %d", &x, &y);
	
	while (s--) {

		// 1 & 2
		while (!fishes.empty()) {
			int i = fishes.front().x;
			int j = fishes.front().y;
			int d = fishes.front().d;
			fishes.pop();

			bool chk = true;
			for (int k = 0; k < 8; k++) {
				int nd = (d - k + 7) % 8 + 1;
				int nx = i + dx_f[nd];
				int ny = j + dy_f[nd];

				if (nx < 1 || 4 < nx || ny < 1 || 4 < ny) continue;
				if (nx == x && ny == y) continue;
				if (smell[nx][ny] && smell[nx][ny] - s <= 2) continue;

				chk = false;
				map[nx][ny].push({ nd });
				break;
			}
			if (chk) map[i][j].push(d);
			copies.push({ i, j, d });
		}

		// 3
		d = -1;
		f(x, y, 0, {});
		for (int i = 0; i < 3; i++) {
			x = movement[i].first;
			y = movement[i].second;

			if (map[x][y].size()) {
				map[x][y] = queue<int>();
				smell[x][y] = s;
			}
		}

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				while (!map[i][j].empty()) {
					fishes.push({ i, j, map[i][j].front() });
					map[i][j].pop();
				}
			}
		}

		// 5
		while (!copies.empty()) {
			fishes.push(copies.front());
			copies.pop();
		}
	}

	printf("%d", fishes.size());

	return 0;
}