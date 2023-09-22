#include <iostream>

#define N 505

int h, w, ans;
int H[N];

int main(void) {

	scanf("%d %d", &h, &w);
	for (int i = 1; i <= w; i++) {
		scanf("%d", &H[i]);
	}

	for (int i = h; i; i--) {
		int a = 0, b = 0;
		for (int j = 1; j <= w; j++) {
			if (H[j] >= i) {
				if (a) {
					for (int k = a + 1; k < j; k++) {
						ans += i - H[k];
						H[k] = i;
					}
				}
				a = j;
			}
		}
	}

	printf("%d", ans);

	return 0;
}