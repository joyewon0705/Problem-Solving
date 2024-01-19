#include <iostream>
#include <queue>
using namespace std;

#define N 1010101
typedef pair<int, int> P;

int f, s, g, u, d, ans = -1;
bool chk[N];
queue<P> q;

int main(void) {

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	q.push({ s, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur > f) continue;
		else if (cur < 1) continue;
		else if (cur == g) {
			ans = cnt;
			break;
		}

		if (chk[cur]) continue;
		chk[cur] = true;

		q.push({ cur + u, cnt + 1 });
		q.push({ cur - d, cnt + 1 });
	}

	if (ans < 0) printf("use the stairs");
	else printf("%d", ans);

	return 0;
}