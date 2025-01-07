#include <iostream>
#include <cstring>

#define N 101

int n, l, ans;
int map[N][N];
bool chk[N][N];

int main(void) {

	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	memset(chk, false, sizeof(chk));
	for (int i = 1; i <= n; i++) {
		bool isAns = true;
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j + 1]) continue;
			if (map[i][j] - map[i][j + 1] == 1) {
				if (j + l > n) {
					isAns = false;
					break;
				}
				for (int k = 1; k <= l; k++) {
					if (map[i][j + k] != map[i][j + 1]) {
						isAns = false;
						break;
					}
					chk[i][j + k] = true;
				}
			}
			else if (map[i][j + 1] - map[i][j] == 1) {
				for (int k = 0; k < l; k++) {
					if (map[i][j - k] != map[i][j] || chk[i][j - k]) {
						isAns = false;
						break;
					}
					chk[i][j - k] = true;
				}
			}
			else {
				isAns = false;
				break;
			}
			if (!isAns) break;
		}
		if (isAns) ans++;
	}
	memset(chk, false, sizeof(chk));
	for (int j = 1; j <= n; j++) {
		bool isAns = true;
		for (int i = 1; i < n; i++) {
			if (map[i][j] == map[i + 1][j]) continue;
			if (map[i][j] - map[i + 1][j] == 1) {
				if (i + l > n) {
					isAns = false;
					break;
				}
				for (int k = 1; k <= l; k++) {
					if (map[i + k][j] != map[i + 1][j]) {
						isAns = false;
						break;
					}
					chk[i + k][j] = true;
				}
			}
			else if (map[i + 1][j] - map[i][j] == 1) {
				for (int k = 0; k < l; k++) {
					if (map[i - k][j] != map[i][j] || chk[i - k][j]) {
						isAns = false;
						break;
					}
					chk[i - k][j] = true;
				}
			}
			else {
				isAns = false;
				break;
			}
			if (!isAns) break;
		}
		if (isAns) ans++;
	}

	printf("%d", ans);

	return 0;
}