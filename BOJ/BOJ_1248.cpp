#include <iostream>
#include <algorithm>
using namespace std;

#define N 11

int n;
char S[N][N];
int m[N], ans[N];

bool f(int cur) {
	int low = -10, high = 10;

	if (cur > n) return true;

	for (int i = cur; i; i--) {
		if (S[i][cur] == '+') low = max(1 - m[i], low);
		else if (S[i][cur] == '-') high = min(-1 - m[i], high);
		else {
			if (low > -m[i] || high < -m[i]) return false;
			low = high = -m[i];
		}
	}
	
	for (int i = low; i <= high; i++) {
		ans[cur] = i;
		for (int j = 1; j <= cur; j++) m[j] += i;
		if (f(cur + 1)) return true;
		for (int j = 1; j <= cur; j++) m[j] -= i;
	}
	return false;
}

int main(void) {

	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			scanf("%c", &S[i][j]);
		}
	}

	f(1);

	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

	return 0;
}