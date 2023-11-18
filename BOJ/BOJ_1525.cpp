#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define INF 1<<30
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, c, ans = INF;
int table[9];
queue<pair<int, P>> q;
map<int, bool> chk;

int main(void) {

	for (int i = 0; i < 9; i++) {
		scanf("%d", &m);
		if (m == 0) c = i;
		n = n * 10 + m;
	}

	m = 123456780;
	q.push({ n, { c, 0 }  }); 
	while (!q.empty()) {
		int tbl = q.front().first;
		int spc = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (tbl == m) {
			ans = cnt;
			break;
		}

		if (chk.find(tbl) != chk.end()) continue;
		chk.insert({ tbl, true });

		for (int i = 0; i < 9; i++) {
			table[8 - i] = tbl % 10;
			tbl /= 10;
		}

		int x = spc / 3;
		int y = spc % 3;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || 3 <= nx || ny < 0 || 3 <= ny) continue;

			int nc = nx * 3 + ny;
			int tmp = 0;
			for (int i = 0; i < 9; i++) {
				if (i == spc) tmp = tmp * 10 + table[nc];
				else if (i == nc) tmp = tmp * 10;
				else tmp = tmp * 10 + table[i];
			}
			q.push({ tmp, { nc, cnt + 1 } });
		}
	}

	if (ans >= INF) ans = -1;
	printf("%d", ans);

	return 0;
}