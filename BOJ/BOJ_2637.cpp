#include <iostream>
#include <vector>
using namespace std;

#define N 101

int n, m, x, y, k;
bool chk[N];
int cnt[N][N];
vector<int> v;

void f(int x) {

	if (chk[x]) return;
	chk[x] = true;

	for (int i = 1; i < n; i++) {
		if (!cnt[x][i]) continue;
		f(i);
		int t = cnt[x][i];
		for (int j : v) {
			cnt[x][j] += t * cnt[i][j];
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) chk[i] = true;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &k);
		cnt[x][y] += k;
		chk[x] = false;
	}
	for (int i = 1; i <= n; i++) if (chk[i]) v.push_back(i);

	f(n);

	for (int i : v) {
		if (cnt[n][i]) printf("%d %d\n", i, cnt[n][i]);
	}

	return 0;
}