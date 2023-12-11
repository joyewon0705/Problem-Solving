#include <iostream>

int n;
int prime[4] = { 2, 3, 5, 7 };

bool isPrime(int x) {

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void f(int cur, int cnt) {

	if (cnt == n) {
		printf("%d\n", cur);
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		if (isPrime(cur * 10 + i)) f(cur * 10 + i, cnt + 1);
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < 4; i++) f(prime[i], 1);

	return 0;
}