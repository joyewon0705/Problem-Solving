#include <iostream>
#include <vector>
using namespace std;

#define N 11
#define H 33

typedef pair<int, int> P;

int n, m, h, a, b, ans = -1;
int ladder[H][N];
vector<P> v;

bool isAnswer() {

	for (int i = 1; i <= n; i++) {
		for (a = 1, b = i; a <= h; a++) {
			b += ladder[a][b];
		}
		if (b != i) return false;
	}
	return true;
}

bool f(int cur, int cnt, int loop) {

	if (cnt >= loop) {
		if (isAnswer()) {
			ans = cnt;
			return true;
		}
		return false;
	}

	while (v.size() > cur) {
		int a = v[cur].first;
		int b = v[cur].second;

		cur++;
		if (ladder[a][b]) continue;

		ladder[a][b] = 1;
		ladder[a][b + 1] = -1;
		if (f(cur, cnt + 1, loop)) return true;
		ladder[a][b] = 0;
		ladder[a][b + 1] = 0;
	}
	return false;
}

int main(void) {

	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		ladder[a][b] = 1;
		ladder[a][b + 1] = -1;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j] || ladder[i][j + 1]) continue;
			v.push_back({ i, j });
		}
	}

	for (int i = 0; i < 4; i++) {
		if (f(0, 0, i)) break;
	}

	printf("%d", ans);

	return 0;
}