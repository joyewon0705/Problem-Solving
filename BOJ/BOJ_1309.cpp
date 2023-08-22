#include <iostream>

#define MOD 9901
#define N 101010

int n, ans;
int m[N][3];

int main(void) {

	scanf("%d", &n);

	m[1][0] = 1; m[1][1] = 1;  m[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		m[i][0] = (m[i - 1][0] + m[i - 1][1] + m[i - 1][2]) % MOD;
		m[i][1] = (m[i - 1][0] + m[i - 1][2]) % MOD;
		m[i][2] = (m[i - 1][0] + m[i - 1][1]) % MOD;
	}

	ans = (m[n][0] + m[n][1] + m[n][2]) % MOD;
	printf("%d", ans);

	return 0;
}