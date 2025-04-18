#include <iostream>

int c, ans;
bool chk[12];
int a[12][12];

void f(int cur, int cnt, int val) {

	if (cnt == 11) {
		if (ans < val) ans = val;
		return;
	}
	if (cur > 11) return;

	for (int j = 1; j <= 11; j++) {
		if (!chk[j] && a[cur][j]) {
			chk[j] = true;
			f(cur + 1, cnt + 1, val + a[cur][j]);
			chk[j] = false;
		}
	}
}

int main(void) {

	scanf("%d", &c);
	while (c--) {
		ans = 0;
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		f(1, 0, 0);

		printf("%d\n", ans);
	}

	return 0;
}