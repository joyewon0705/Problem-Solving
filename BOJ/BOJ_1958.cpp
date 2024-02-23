#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 111

char a[N], b[N], c[N];
int dp[N][N][N];

int main(void) {

	a[0] = '_', b[0] = '_', c[0] = '_';
	scanf("%s", &a[1]);
	scanf("%s", &b[1]);
	scanf("%s", &c[1]);

	for (int i = 1; i < strlen(a); i++) {
		for (int j = 1; j < strlen(b); j++) {
			for (int k = 1; k < strlen(c); k++) {
				if (a[i] == b[j] && b[j] == c[k]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		} 
	}

	printf("%d", dp[strlen(a) - 1][strlen(b) - 1][strlen(c) - 1]);

	return 0;
}