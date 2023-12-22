#include <iostream>
#include <cmath>
using namespace std;

int x, y, d, t;
double dst, ans;

int main(void) {

	scanf("%d %d %d %d", &x, &y, &d, &t);

	dst = sqrt(x * x + y * y);
	if ((double)d / t > 1) {
		int j = dst / d;
		dst -= j * d;
		ans = dst;
		if (j) {
			if (ans > t) ans = t;
		}
		else {
			if (ans > t + abs(dst - d)) ans = t + abs(dst - d);
			if (ans > 2 * t) ans = 2 * t;
		}
		ans += j * t;
	}
	else ans = dst;

	printf("%.9f", ans);

	return 0;
}