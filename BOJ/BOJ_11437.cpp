#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 50505
typedef pair<int, int> P;

int n, m, a, b;
int parent[N], depth[N];
vector<int> v[N];
queue<P> q;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push({ 1, 1 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		depth[cur] = cnt;
		for (int child : v[cur]) {
			if (depth[child]) continue;
			parent[child] = cur;
			q.push({ child, cnt + 1 });
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (depth[a] < depth[b]) {
			int t = depth[b] - depth[a];
			while (t--) b = parent[b];
		}
		else if (depth[a] > depth[b]) {
			int t = depth[a] - depth[b];
			while (t--) a = parent[a];
		}
		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
		printf("%d\n", a);
	}

	return 0;
}