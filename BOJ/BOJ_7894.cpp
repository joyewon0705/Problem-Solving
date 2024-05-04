#include <iostream>
#include <cmath>
using namespace std;

#define N 10101010

int t, n, m;
double a[N];

int main(void) {
	
	a[0] = 1;
	for (int i = 1; i < N; i++) {
		a[i] = a[i - 1] + log10(i);
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		printf("%d\n", (int)a[m]);
	}

	return 0;
}