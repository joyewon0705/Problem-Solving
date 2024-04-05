#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 101

int n, m, a, b;
vector<int> p[N], c[N];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		p[a].push_back(b);
		c[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		vector<bool> v = vector<bool>(n + 1, false);
		queue<int> q;

		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (v[cur]) continue;
			v[cur] = true;
			cnt++;

			for (int next : p[cur]) q.push(next);
		}
		cnt--;
		v[i] = false; 
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (v[cur]) continue;
			v[cur] = true;
			cnt++;

			for (int next : c[cur]) q.push(next);
		}

		printf("%d\n", n - cnt);
	}

	return 0;
}