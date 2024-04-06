#include <iostream>
#include <cstring>

#define N 4040

int len1, len2, ans;
int d[N];
char str1[N], str2[N];

int main(void) {

	scanf("%s", str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 1; i <= len1; i++) {
		for (int j = len2; j; j--) {
			if (str1[i - 1] == str2[j - 1]) d[j] = d[j - 1] + 1;
			else d[j] = 0;
			if (ans < d[j]) ans = d[j];
		}
	}

	printf("%d", ans);

	return 0;
}
