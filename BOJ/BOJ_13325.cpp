#include <iostream>
#include <cmath>
using namespace std;

#define N 2121212

int k, n, ans;
int w[N], m[N];

int f(int cur, int lvl) {

	if (lvl == k) return w[cur];

	m[cur] = max(f(2 * cur, lvl + 1), f(2 * cur + 1, lvl + 1));
	return w[cur] + m[cur];
}

int main(void) {

	scanf("%d", &k);
	n = pow(2, k + 1);
	for (int i = 2; i < n; i++) {
		scanf("%d", &w[i]);
	}

	f(1, 0);

	for (int i = 2; i < n; i++) {
		ans += m[i / 2] - m[i];
	}
	printf("%d", ans);

	return 0;
}