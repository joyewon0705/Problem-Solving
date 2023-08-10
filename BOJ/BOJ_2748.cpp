#include <iostream>

#define N 100

int n;
long long f[N] = { 0, 1, 1 };

long long fibonacci(int n) {
	if (f[n]) return f[n];
	else return f[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {

	scanf("%d", &n);
	printf("%lld", fibonacci(n));

	return 0;
}