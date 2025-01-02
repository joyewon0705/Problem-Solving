#include <iostream>
#include <cmath>
using namespace std;

#define N 22

int n, ans = 1<<30;
bool team[N];
int s[N][N];

void f(int cur, int cnt) {

	if (cnt == n / 2) {
		int st = 0, lk = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (team[i] != team[j]) continue;
				if (team[i]) st += s[i][j] + s[j][i];
				else lk += s[i][j] + s[j][i];
			}
		}
		int val = abs(st - lk);
		if (ans > val) ans = val;
		return;
	}
	if (n - cur + 1 < n / 2 - cnt) return;

	team[cur] = true;
	f(cur + 1, cnt + 1);
	team[cur] = false;
	f(cur + 1, cnt);
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &s[i][j]);
		}
	}

	f(2, 0);

	printf("%d", ans);

	return 0;
}