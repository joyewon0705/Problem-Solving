#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define LEN 1010

int len1, len2;
char str1[LEN], str2[LEN];
int dp[LEN][LEN];

int main(void) {

	scanf("%s", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);
	for (int i = 1; i <= max(len1, len2); i++) {
		dp[0][i] = i;
		dp[i][0] = i;
	}

	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (str1[i] == str2[j])
				dp[i + 1][j + 1] = dp[i][j];
			else
				dp[i + 1][j + 1] = min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1])) + 1;
		}
	}

	printf("%d", dp[len1][len2]);

	return 0;
}