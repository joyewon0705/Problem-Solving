#include <iostream>
#include <queue>
using namespace std;

#define N 101

int n, k, st, ed, cnt, ans;
int a[2 * N];
bool chk[2 * N];
queue<int> q;

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%d", &a[i]);
	}

	st = 1; ed = n;
	while (cnt < k) {
		ans++;

		st = st == 1 ? 2 * n : st - 1;
		ed = ed == 1 ? 2 * n : ed - 1;

		for (int i = q.size(); i; i--) {
			int cur = q.front();
			q.pop();

			int next = (cur % (2 * n)) + 1;
			if (cur != ed && a[next] && !chk[next]) {
				chk[cur] = false;
				cur = next;
				a[cur]--;
				if (a[cur] == 0) cnt++;
				chk[cur] = true;
			}

			if (cur == ed) {
				chk[cur] = false;
				continue;
			}

			q.push(cur);
		}

		if (a[st]) {
			a[st]--;
			if (a[st] == 0) cnt++;
			chk[st] = true;
			q.push(st);
		}
	}

	printf("%d", ans);

	return 0;
}