#include <iostream>

#define MAX 21
#define N 101

int n, in;
long long cnt[N][MAX];

int main(void) {

	scanf("%d", &n);
	scanf("%d", &in);
	cnt[0][in]++;
	for (int i = 1; i < n - 1; i++) {
		scanf("%d", &in);

		for (int j = 0; j < MAX; j++) {
			if (j + in < MAX) cnt[i][j + in] += cnt[i - 1][j];
			if (j - in > -1) cnt[i][j - in] += cnt[i - 1][j];
		}
	}
	scanf("%d", &in);
	printf("%lld", cnt[n - 2][in]);

	return 0;
}