#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 55

int n, in, ans;
vector<int> v[N];
queue<int> q;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		if (in < 0) {
			q.push(i); continue;
		}
		v[in].push_back(i);
	}
	scanf("%d", &in);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == in) break;

		int cnt = 0;
		for (int child : v[cur]) {
			if (child == in) continue;
			cnt++;
			q.push(child);
		}
		if (!cnt) ans++;
	}

	printf("%d", ans);

	return 0;
}