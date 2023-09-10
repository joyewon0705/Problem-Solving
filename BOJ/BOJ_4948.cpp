#include <iostream>
#include <cstring>

#define N 303030

bool isPrime[N];
int n;

int main(void) {

	memset(isPrime, true, sizeof(isPrime));

	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i < N; ) {
		for (int j = i + 1; j < N; j++) {
			if (isPrime[j] && j % i == 0) isPrime[j] = false;
		}
		while (!isPrime[++i]);
	}

	scanf("%d", &n);
	while (n > 0) {
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i]) cnt++;
		}
		printf("%d\n", cnt);
		scanf("%d", &n);
	}

	return 0;
}