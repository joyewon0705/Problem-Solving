#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int n, m, l, k, x, y, ans;
vector<P> v;

int main(void) {

	scanf("%d %d %d %d", &n, &m, &l, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			x = v[i].first;
			y = v[j].second;

			int cnt = 0;
			for (P s : v) {
				if (s.first < x || x + l < s.first || s.second < y || y + l < s.second) continue;
				cnt++;
			}

			if (ans < cnt) ans = cnt;
		}
	}

	printf("%d", k - ans);

	return 0;
}