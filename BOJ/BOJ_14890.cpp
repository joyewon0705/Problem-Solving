#include <iostream>

#define N 101

int n, l, ans;
int map[N][N];

int main(void) {

	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		bool isPossible = true;
		int height = map[i][1], cnt = 1;
		for (int j = 2; j <= n; ) {
			if (height == map[i][j]) {
				cnt++;
				j++;
			}
			else if (height - map[i][j] == 1) {
				height = map[i][j], cnt = 1;
				while (height == map[i][++j]) cnt++;
				if (cnt < l) {
					isPossible = false;
					break;
				}
				cnt -= l;
			}
			else if (map[i][j] - height == 1) {
				if (cnt < l) {
					isPossible = false;
					break;
				}
				height = map[i][j++], cnt = 1;
			}
			else {
				isPossible = false;
				break;
			}
		}
		if (isPossible) ans++;
	}

	for (int j = 1; j <= n; j++) {
		bool isPossible = true;
		int height = map[1][j], cnt = 1;
		for (int i = 2; i <= n; ) {
			if (height == map[i][j]) {
				cnt++;
				i++;
			}
			else if (height - map[i][j] == 1) {
				height = map[i][j], cnt = 1;
				while (height == map[++i][j]) cnt++;
				if (cnt < l) {
					isPossible = false;
					break;
				}
				cnt -= l;
			}
			else if (map[i][j] - height == 1) {
				if (cnt < l) {
					isPossible = false;
					break;
				}
				height = map[i++][j], cnt = 1;
			}
			else {
				isPossible = false;
				break;
			}
		}
		if (isPossible) ans++;
	}

	printf("%d", ans);

	return 0;
}