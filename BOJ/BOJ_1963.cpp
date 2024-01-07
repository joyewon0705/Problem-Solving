#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 10001
typedef pair<int, int> P;

int t, a, b, ans;
bool prime[N], chk[N];
queue<P> q;

int main(void) {

	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= N; ) {
		for (int j = i + 1; j < N; j++) {
			if (j % i == 0) prime[j] = false;
		}
		while (!prime[++i]);
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);

		q = queue<P>();
		memset(chk, false, sizeof(chk));
		ans = -1;
		q.push({ a, 0 });
		while (!q.empty()) {
			int cur = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (cur < 1000) continue;
			if (!prime[cur]) continue;
			if (cur == b) {
				ans = cnt;
				break;
			}

			if (chk[cur]) continue;
			chk[cur] = true;

			for (int i = 0; i < 10; i++) {
				q.push({ i * 1000 + cur % 1000, cnt + 1 });
				q.push({ cur / 1000 * 1000 + i * 100 + cur % 100, cnt + 1 });
				q.push({ cur / 100 * 100 + i * 10 + cur % 10, cnt + 1 });
				q.push({ cur / 10 * 10 + i, cnt + 1 });
			}
		}

		if (ans < 0) printf("Impossible\n");
		else printf("%d\n", ans);
	}

	return 0;
}