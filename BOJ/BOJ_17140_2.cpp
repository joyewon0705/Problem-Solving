#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define N 101

typedef pair<int, int> P;

int r, c, k, x, y, ans;
int a[N][N];

bool cmp(P a, P b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void) {

	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	x = y = 3;
	while (ans < 100 && a[r][c] != k) {
		
		if (x >= y) {
			int ny = 0;
			for (int i = 1; i <= x; i++) {
				int s, cnt[N] = { 0 };
				vector<int> chk;
				vector<P> v;

				for (int j = 1; j <= y; j++) {
					if (a[i][j] == 0) continue;
					cnt[a[i][j]]++;
					if (cnt[a[i][j]] == 1) chk.push_back(a[i][j]);
				}
				
				for (int cur : chk) v.push_back({ cur, cnt[cur] });
				sort(v.begin(), v.end(), cmp);
				s = min(100, (int)v.size());
				if (ny < 2 * s) ny = 2 * s;

				for (int k = 0; k < s; k++) {
					a[i][2 * k + 1] = v[k].first;
					a[i][2 * k + 2] = v[k].second;
				}
				for (int j = 2 * s + 1; j <= y; j++) a[i][j] = 0;
			}
			y = ny;
		}
		else {
			int nx = 0;
			for (int j = 1; j <= y; j++) {
				int s, cnt[N] = { 0 };
				vector<int> chk;
				vector<P> v;
				
				for (int i = 1; i <= x; i++) {
					if (a[i][j] == 0) continue;
					cnt[a[i][j]]++;
					if (cnt[a[i][j]] == 1) chk.push_back(a[i][j]);
				}

				for (int cur : chk) v.push_back({ cur, cnt[cur] });
				sort(v.begin(), v.end(), cmp);
				s = min(100, (int)v.size());
				if (nx < 2 * s) nx = 2 * s;

				for (int k = 0; k < s; k++) {
					a[2 * k + 1][j] = v[k].first;
					a[2 * k + 2][j] = v[k].second;
				}
				for (int i = 2 * s + 1; i <= x; i++) a[i][j] = 0;
			}
			x = nx;
		}
		
		ans++;
	}

	if (a[r][c] != k) ans = -1;
	printf("%d", ans);

	return 0;
}