#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 1010
typedef pair<int, int> P;

int s, ans;
int d[2 * N][2 * N];
queue<pair<int, P>> q;

int main(void) {

	scanf("%d", &s);

	for (int i = 0; i <= 2 * s; i++)
		for (int j = 0; j <= 2 * s; j++)
			d[i][j] = INF;

	ans = INF;
	q.push({ 1, { 0, 0 } });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second.first;
		int chk = q.front().second.second;
		q.pop();

		if (cur == s) {
			if (ans > cnt) ans = cnt;
			continue;
		}

		if (d[cur][chk] <= cnt) continue;
		d[cur][chk] = cnt;

		if (cur < s) {
			q.push({ cur, { cnt + 1, cur } });
			q.push({ cur + chk, { cnt + 1, chk } });
		}
		if (cur) q.push({ cur - 1, { cnt + 1, chk } });
	}

	printf("%d", ans);

	return 0;
}