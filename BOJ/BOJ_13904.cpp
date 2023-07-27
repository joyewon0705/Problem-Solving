#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1010
typedef pair<int, int> P;

int n, d, w, cnt, ans;
int chk[N];
vector<P> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &d, &w);
		v.push_back({ w, d });
		cnt = max(cnt, d);
	}

	sort(v.begin(), v.end(), greater<P>());
	for (P cur : v) {
		for (int i = cur.second; i; i--) {
			if (chk[i] < cur.first) {
				chk[i] = cur.first;
				break;
			}
		}
	}
	for (int i = 1; i <= cnt; i++) ans += chk[i];

	printf("%d", ans);

	return 0;
}