#include <iostream>

int xa, xb, xc, ya, yb, yc, d;

int main(void) {

	scanf("%d %d", &xa, &ya);
	scanf("%d %d", &xb, &yb);
	scanf("%d %d", &xc, &yc);

	d = (xb - xa) * (yc - ya) - (xc - xa) * (yb - ya);

	if (d > 0) d = 1;
	else if (d < 0) d = -1;
	printf("%d", d);

	return 0;
}