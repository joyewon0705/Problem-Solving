#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 505

int n, in;
int cnt[N], t[N];
vector<int> a[N], b[N];
queue<int> q;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		while (true) {
			scanf("%d", &in);
			if (in < 0) break;
			cnt[i]++;
			a[in].push_back(i);
			b[i].push_back(in);
		}
		if (cnt[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int max = 0;
		for (int before : b[cur]) {
			if (max < t[before]) max = t[before];
		}
		t[cur] += max;

		for (int next : a[cur]) {
			cnt[next]--;
			if (cnt[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", t[i]);
	}

	return 0;
}