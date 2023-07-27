#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 202

bool isPossible = true;
int n, m, in;
int chk[N];
vector<int> v[N];
queue<int> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &in);
			if (in) v[i].push_back(j);
		}
	}

	scanf("%d", &in);
	q.push(in);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (chk[cur]) continue;
		chk[cur] = in;

		for (int next : v[cur])
			q.push(next);
	}

	for (int i = 1; i < m; i++) {
		scanf("%d", &in);
		if (!chk[in]) isPossible = false;
	}

	if (isPossible) printf("YES");
	else printf("NO");

	return 0;
}