#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 101010
#define M 1010
typedef pair<int, int> P;

int n, k, m, ans = -1;
bool chk[M];
int ht[M][M];
vector<int> v[N];
queue<P> q;

int main(void) {

	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			scanf("%d", &ht[i][j]);
			v[ht[i][j]].push_back(i);
		}
	}

	for (int next : v[1]) q.push({ next, 1 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (chk[cur]) continue;
		chk[cur] = true;

		for (int i = 1; i <= k; i++) {
			int no = ht[cur][i];

			if (no == n) {
				ans = cnt + 1;
				q = queue<P>();
				break;
			}

			for (int next : v[no]) {
				if (chk[next]) continue;
				q.push({ next , cnt + 1 });
			}
		}
	}

	if (n == 1) ans = 1;
	printf("%d", ans);

	return 0;
}