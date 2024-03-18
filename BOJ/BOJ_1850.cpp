#include <iostream>

long long a, b;

int main(void) {

	scanf("%lld %lld", &a, &b);

	if (a < b) {
		long long t = a;
		a = b;
		b = t;
	}

	while (a % b) {
		long long t = a % b;
		a = b;
		b = t;
	}

	for (int i = 0; i < b; i++) printf("1");

	return 0;
}