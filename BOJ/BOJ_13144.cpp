#include <iostream>

#define N 101010

int n, l, r;
long long ans;
bool c[N];
int a[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	l = 1; r = 2;
	c[a[l]] = true;
	while (l <= n) {
		if (r > n || c[a[r]]) {
			ans += r - l;
			c[a[l]] = false;
			l++;
		}
		else {
			c[a[r]] = true;
			r++;
		}
	}

	printf("%lld", ans);

	return 0;
}