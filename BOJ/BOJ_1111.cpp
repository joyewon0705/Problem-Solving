#include <iostream>

#define N 55

int n;
int m[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
	}

	if (n == 1) printf("A");
	else if (n == 2) {
		if (m[0] == m[1]) printf("%d", m[0]);
		else printf("A");
	}
	else {
		if (m[0] == m[1]) {
			for (int i = 1; i < n; i++) {
				if (m[i - 1] != m[i]) {
					printf("B");
					return 0;
				}
			}
			printf("%d", m[0]);
		}
		else {
			int t1 = 1, t2 = 2, t3 = 3, t4 = 4;
			for (int i = 0; i < n - 1; i++) {
				if (m[i]) {
					t1 = m[i];
					t2 = m[i + 1];
					break;
				}
			}
			for (int i = 0; i < n - 1; i++) {
				if (m[i] != t1) {
					t3 = m[i];
					t4 = m[i + 1];
					break;
				}
			}

			int b = (t2 * t3 - t4 * t1) / (t3 - t1);
			int a = (t2 - b) / t1;
			
			for (int i = 1; i < n; i++) {
				if (m[i] != m[i - 1] * a + b) {
					printf("B");
					return 0;
				}
			}
			printf("%d", m[n - 1] * a + b);
		}
	}

	return 0;
}