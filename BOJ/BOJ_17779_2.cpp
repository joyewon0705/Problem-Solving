#include <iostream>
#include <cmath>
using namespace std;

#define INF 1<<30
#define N 22

int n, sum, ans = INF;
int a[N][N];

int f(int x, int y, int d1, int d2) {

	if (x + d1 + d2 > n || y <= d1 || y + d2 > n) return INF;

	int maxx = 0, minn = INF, summ = 0, val;

	val = 0;
	for (int i = 1; i < x; i++)
		for (int j = 1; j <= y; j++) val += a[i][j];
	for (int i = x; i < x + d1; i++) 
		for (int j = 1; j < y - (i - x); j++) val += a[i][j];
	maxx = max(maxx, val);
	minn = min(minn, val);
	summ += val;

	val = 0;
	for (int i = 1; i < x; i++)
		for (int j = y + 1; j <= n; j++) val += a[i][j];
	for (int i = x; i <= x + d2; i++)
		for (int j = y + 1 + (i - x); j <= n; j++) val += a[i][j];
	maxx = max(maxx, val);
	minn = min(minn, val);
	summ += val;

	val = 0;
	for (int i = x + d1; i < x + d1 + d2; i++)
		for (int j = 1; j < y - d1 - (x + d1 - i); j++) val += a[i][j];
	for (int i = x + d1 + d2; i <= n; i++)
		for (int j = 1; j < y - d1 + d2; j++) val += a[i][j];
	maxx = max(maxx, val);
	minn = min(minn, val);
	summ += val;

	val = 0;
	for (int i = x + d2 + 1; i <= x + d1 + d2; i++)
		for (int j = y + d2 + (x + d2 - i) + 1; j <= n; j++) val += a[i][j];
	for (int i = x + d1 + d2 + 1; i <= n; i++)
		for (int j = y + d2 - d1; j <= n; j++) val += a[i][j];
	maxx = max(maxx, val);
	minn = min(minn, val);
	summ += val;

	val = sum - summ;
	maxx = max(maxx, val);
	minn = min(minn, val);

	return maxx - minn;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					ans = min(ans, f(x, y, d1, d2));
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}