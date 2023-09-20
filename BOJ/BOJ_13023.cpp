#include <iostream>
#include <vector>
using namespace std;

#define N 2020

bool ans;
int n, m, a, b;
bool chk[N];
vector<int> v[N];

bool dfs(int cur, int cnt) {

	if (cnt == 5) return true;
	if (cur >= n) return false;

	for (int next : v[cur]) {
		if (chk[next]) continue;

		chk[next] = true;
		if (dfs(next, cnt + 1)) return true;
		chk[next] = false;
	}
	return false;
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		chk[i] = true;
		if (dfs(i, 1)) {
			ans = true;
			break;
		}
		chk[i] = false;
	}

	if (ans) printf("1");
	else printf("0");

	return 0;
}