#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 11

int n, m, in, ans = INF;
bool set[N], chk[N];
int p[N];
vector<int> v[N];

void f(int cur) {
	
	if (cur > n) {
		int a = 0, b = 0;
		vector<int> list1, list2;
		queue<int> q;

		for (int i = 1; i <= n; i++) {
			chk[i] = false;
			if (set[i]) {
				a += p[i];
				list1.push_back(i);
			}
			else {
				b += p[i];
				list2.push_back(i);
			}
		}
		if (list1.empty() || list2.empty()) return;

		q.push(list1[0]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (chk[cur]) continue;
			chk[cur] = true;

			for (int next : v[cur]) {
				if (set[next]) q.push(next);
			}
		}

		q.push(list2[0]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (chk[cur]) continue;
			chk[cur] = true;

			for (int next : v[cur]) {
				if (!set[next]) q.push(next);
			}
		}

		for (int i = 1; i <= n; i++) if (!chk[i]) return;
		if (ans > abs(a - b)) ans = abs(a - b);
		return;
	}

	set[cur] = true;
	f(cur + 1);
	set[cur] = false;
	f(cur + 1);
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &in);
			v[i].push_back(in);
			v[in].push_back(i);
		}
	}

	f(1);

	if (ans >= INF) printf("-1");
	else printf("%d", ans);

	return 0;
}