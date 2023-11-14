#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1010
typedef pair<int, int> P;

int t, n, m, a, b, ans;
bool chk[N];
vector<P> v;

bool cmp(P a, P b) {

	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		memset(chk, false, sizeof(chk));
		v = vector<P>();

		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end(), cmp);

		ans = 0;
		for (P cur : v) {
			a = cur.first;
			b = cur.second;

			for (; a <= b; a++) {
				if (chk[a]) continue;
				chk[a] = true;
				ans++;
				break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}