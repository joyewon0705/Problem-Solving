#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define N 16
typedef pair<int, int> P;
typedef pair<int, P> PP;

int n, m, d, cnt, ans;
bool init_map[N][N], map[N][N];
vector<P> init_enemies, enemies;
priority_queue<PP, vector<PP>, greater<PP>> pq[N];

int main(void) {

	scanf("%d %d %d", &n, &m, &d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &init_map[i][j]);
			if (init_map[i][j]) init_enemies.push_back({ i, j });
		}
	}

	for (int a1 = 1; a1 <= m; a1++) {
		for (int a2 = a1 + 1; a2 <= m; a2++) {
			for (int a3 = a2 + 1; a3 <= m; a3++) {
				memcpy(map, init_map, sizeof(map));
				enemies = init_enemies;
				vector<int> archers = { a1, a2, a3 };
				cnt = 0;

				while (true) {
					vector<P> attack;
					
					for (int a : archers) {
						pq[a] = priority_queue<PP, vector<PP>, greater<PP>>();

						for (P e : enemies) {
							int dist = abs(n + 1 - e.first) + abs(a - e.second);
							if (dist <= d) pq[a].push({ dist, { e.second, e.first } });
						}
						if (pq[a].size()) attack.push_back({ pq[a].top().second.second, pq[a].top().second.first });
					}

					for (P e : attack) {
						if (map[e.first][e.second]) {
							map[e.first][e.second] = false;
							cnt++;
						}
					}

					enemies = vector<P>();
					bool isExist = false;
					for (int i = n; i; i--) {
						for (int j = m; j; j--) {
							if (map[i][j]) {
								if (i < n) {
									map[i + 1][j] = map[i][j];
									enemies.push_back({ i + 1, j });
								}
								map[i][j] = 0;
								isExist = true;
							}
						}
					}

					if (!isExist) break;
				}

				if (ans < cnt) ans = cnt;
			}
		}
	}

	printf("%d", ans);

	return 0;
}