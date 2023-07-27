#pragma warning(disable:4996)
#include <stdio.h>
#define N 64
char quadtree[N][N];

int main(void) {
	void Divide(int n, int x, int y);
	int n;
	char s[N + 1];

	// 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			quadtree[i][j] = s[j];
	}

	// 출력
	Divide(n, 0, 0);

	return 0;
}

void Divide(int n, int x, int y) {
	_Bool isUnity = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (quadtree[x][y] != quadtree[x + i][y + j]) {
				isUnity = 0;
				break;
			}
		}
		if (!isUnity) break;
	}

	if (isUnity || n == 1) printf("%c", quadtree[x][y]);
	else {
		n /= 2;
		printf("(");
		Divide(n, x, y);
		Divide(n, x, y + n);
		Divide(n, x + n, y);
		Divide(n, x + n, y + n);
		printf(")");
	}

	return;
}