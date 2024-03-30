#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 505

int n;
int dp[N][N];
char DNA[N];

int main(void) {

	scanf("%s", DNA);

	n = strlen(DNA);
	for (int h = 1; h < n; h++) {
		for (int i = 0; i + h < n; i++) {
			int j = i + h;
			if ((DNA[i] == 'a' && DNA[j] == 't') || (DNA[i] == 'g' && DNA[j] == 'c'))
				dp[i][j] = dp[i + 1][j - 1] + 2;
			for (int k = i; k < j; k++)
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}

	printf("%d", dp[0][n - 1]);

	return 0;
}