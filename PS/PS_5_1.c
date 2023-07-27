#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define N 1515
int A[N][N] = { 0 }, B[N][N] = { 0 };
long D[N][N] = { 0 };
char c;
int n, m;
long sum;

int main(void) {

	// 입력
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (c = getchar()) {
				if (c == 'A') {
					scanf("%d", &A[i][j]);
					break;
				}
				else if (c == 'B') {
					scanf("%d", &B[i][j]);
					break;
				}
			}
			if (j != 0) {
				A[i][j] += A[i][j - 1];
				B[i][j] += B[i][j - 1];
			}
		}
	}

	// 세팅
	D[0][0] = B[0][m - 1] - B[0][0];
	for (int i = 1; i < n; i++)
		D[i][0] = D[i - 1][0] + B[i][m - 1] - B[i][0];
	for (int j = 1; j < m; j++)
		D[0][j] = B[0][m - 1] - B[0][j];

	// 계산
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			D[i][j] = D[i][j - 1] - B[i][j] + B[i][j - 1];
			sum = A[i][j - 1] + B[i][m - 1] - B[i][j];
			if (D[i - 1][j - 1] > D[i - 1][j]) sum += D[i - 1][j - 1];
			else sum += D[i - 1][j];
			if (sum > D[i][j]) D[i][j] = sum;
		}
	}

	// 출력
	printf("%ld", D[n - 1][m - 1]);

	return 0;
}

/* 디버깅용 배열 출력
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", D[i][j]);
		}
		printf("\n");
	}
*/