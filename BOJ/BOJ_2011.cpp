#include <iostream>
#include <cstring>

#define MOD 1000000
#define N 5050

int len, val, ans;
char st[N];
int pw[N], dp[N];

int main(void) {

	scanf("%s", st);

	len = strlen(st);
	pw[0] = st[0] - '0';
	if (pw[0] > 0) dp[0] = 1;
	pw[1] = st[1] - '0';
	if (pw[1] > 0) dp[1] = dp[0];
	if (pw[0] > 0) {
		val = pw[0] * 10 + pw[1];
		if (val > 0 && val < 27) dp[1]++;
	}
	for (int i = 2; i < len; i++) {
		pw[i] = st[i] - '0';
		if (pw[i] > 0) dp[i] = dp[i - 1];
		if (pw[i - 1] > 0) {
			val = pw[i - 1] * 10 + pw[i];
			if (val > 0 && val < 27) dp[i] += dp[i - 2];
		}
		dp[i] %= MOD;
	}

	printf("%d", dp[len - 1]);

	return 0;
}