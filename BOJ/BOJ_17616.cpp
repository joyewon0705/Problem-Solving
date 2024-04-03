#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 101010

int n, m, x, a, b, u, v;
bool isVisit[N];
vector<int> p[N], c[N];
queue<int> q;

int main(void) {

	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		p[b].push_back(a);
		c[a].push_back(b);
	}

	u = 1;
	for (int parent : p[x]) q.push(parent);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (isVisit[cur]) continue;
		isVisit[cur] = true;
		u++;

		for (int parent : p[cur]) q.push(parent);
	}

	v = n;
	for (int child : c[x]) q.push(child);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (isVisit[cur]) continue;
		isVisit[cur] = true;
		v--;

		for (int child : c[cur]) q.push(child);
	}

	printf("%d %d", u, v);

	return 0;
}