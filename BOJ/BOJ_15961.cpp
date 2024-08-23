#include <iostream>

#define N 3030303

int n, d, k, c, cnt, ans;
int sushi[N], chk[N];

int main(void) {

	scanf("%d %d %d %d", &n, &d, &k, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sushi[i]);
	}

	if (chk[c] == 0) cnt++;
	chk[c]++;
	for (int i = 0; i < k; i++) {
		if (chk[sushi[i]] == 0) cnt++;
		chk[sushi[i]]++;
	}
	ans = cnt;
	chk[sushi[0]]--;
	if (chk[sushi[0]] == 0) cnt--;
	for (int i = 1, j = k; i < n; i++, j++) {
		j %= n;
		if (chk[sushi[j]] == 0) cnt++;
		chk[sushi[j]]++;
		if (ans < cnt) ans = cnt;
		chk[sushi[i]]--;
		if (chk[sushi[i]] == 0) cnt--;
	}

	printf("%d", ans);

	return 0;
}