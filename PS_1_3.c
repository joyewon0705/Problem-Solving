#include <stdio.h>
#pragma warning(disable:4996)
_Bool answer[3072][6143] = { 0 };

int main(void) {
	void Divide(int n, int, int);
	int n;

	scanf("%d", &n);
	Divide(n, 0, n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (2 * n - 1); j++) {
			if (answer[i][j] == 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

void Divide(int n, int x, int y) {
	if (n == 3) {
		answer[x][y] = 1;
		answer[x + 1][y - 1] = 1;
		answer[x + 1][y + 1] = 1;
		answer[x + 2][y - 2] = 1; 
		answer[x + 2][y - 1] = 1; 
		answer[x + 2][y] = 1; 
		answer[x + 2][y + 1] = 1; 
		answer[x + 2][y + 2] = 1;
		return;
	}
	Divide(n / 2, x, y);
	Divide(n / 2, x + n / 2, y - n / 2);
	Divide(n / 2, x + n / 2, y + n / 2);
	return;
}