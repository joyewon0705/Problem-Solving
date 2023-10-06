#include <iostream>
#include <vector>
using namespace std;

#define N 101010

int n, r, q, u, v;
bool isVisit[N];
int dp[N];
vector<int> edge[N];

int dfs(int cur) {
	int ret = 1;

	if (isVisit[cur]) return 0;
	isVisit[cur] = true;

	for (int next : edge[cur]) {
		ret += dfs(next);
	}
	return dp[cur] = ret;
}

int main(void) {

	scanf("%d %d %d", &n, &r, &q);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(r);
	for (int i = 0; i < q; i++) {
		scanf("%d", &u);
		printf("%d\n", dp[u]);
	}

	return 0;
}