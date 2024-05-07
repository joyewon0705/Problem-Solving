#include <iostream>

#define N 5050
#define M 202020

int n, ans;
bool isVisit[2 * M];
int A[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (isVisit[A[i] - A[j] + M]) {
				ans++;
				break;
			}
		}

		for (int j = 1; j <= i; j++) {
			isVisit[A[i] + A[j] + M] = true;
 		}
	}

	printf("%d", ans);

	return 0;
}