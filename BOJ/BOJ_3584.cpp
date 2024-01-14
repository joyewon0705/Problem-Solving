#include <iostream>

#define N 10101

int t, n, a, b, ans;
bool chk[N];
int parent[N];

void f1(int x) {
	
	chk[x] = true;
	if (parent[x] == x) return;
	f1(parent[x]);
}

void f2(int x) {

	if (chk[x]) {
		ans = x;
		return;
	}
	f2(parent[x]);
}

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			chk[i] = false;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d %d", &a, &b);
			parent[b] = a;
		}
		scanf("%d %d", &a, &b);

		f1(a);
		f2(b);

		printf("%d\n", ans);
	}

	return 0;
}