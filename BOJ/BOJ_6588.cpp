#include <iostream>
#include <cstring>

#define N 1010101

int n, a, b;
bool isPrime[N];

int main(void) {

	memset(isPrime, true, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	for (int i = 3; i * i < N; ) {
		for (int j = i + 2; j < N; j += 2) {
			if (j % i == 0) isPrime[j] = false;
		}
		do i += 2;
		while (!isPrime[i]);
	}

	scanf("%d", &n);
	while (n) {
		a = b = 0;
		for (int i = 3; i + i <= n; i += 2) {
			if (!isPrime[i]) continue;
			if (isPrime[n - i]) {
				a = i;
				b = n - i;
				break;
			}
		}

		if (a + b) printf("%d = %d + %d\n", n, a, b);
		else printf("Goldbach's conjecture is wrong.\n");
		scanf("%d", &n);
	}

	return 0;
}