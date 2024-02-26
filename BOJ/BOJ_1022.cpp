#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int r1, r2, c1, c2, mx;

int f(int x, int y) {
	int a = max(abs(x), abs(y));
	int b = 2 * a;
	int c = pow(b + 1, 2);

	if (x == a) return c - (a - y);
	c -= b;
	if (y == -a) return c - (a - x);
	c -= b;
	if (x == -a) return c - (a + y);
	c -= b;
	return c - (a + x);
}

int main(void) {

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			mx = max(mx, f(i, j));
		}
	}
	
	mx = log10(mx) + 1;

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			printf("%*d ", mx, f(i, j));
		}
		printf("\n");
	}

	return 0;
}