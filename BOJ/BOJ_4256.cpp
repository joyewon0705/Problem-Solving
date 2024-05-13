#include <iostream>

#define N 1010

int t, n;
int pre[N], mid[N];

void f(int cur, int l, int r) {
	for (int i = l; i <= r; i++) {
		if (pre[cur] == mid[i]) {
			f(cur + 1, l, i - 1);
			f(cur + i - l + 1, i + 1, r);
			printf("%d ", pre[cur]);
			return;
		}
	}
}

int main(void) {
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &pre[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &mid[i]);
		}

		f(1, 1, n);
		printf("\n");
	}

	return 0;
}