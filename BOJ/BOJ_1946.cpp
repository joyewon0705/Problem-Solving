#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;
#define N 101010

int t, n, a, b, ans;
bool chk[N];
vector<P> v;

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		memset(chk, false, sizeof(chk));
		v = vector<P>();

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end());

		ans = n;
		for (int i = 0, j = 1; i < n && j < n; ) {
			if (v[i].second < v[j].second) {
				ans--;
				j++;
			}
			else {
				i = j;
				j++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}