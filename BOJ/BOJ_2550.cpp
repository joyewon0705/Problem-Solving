#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 10101
typedef pair<int, int> P;

int n, cnt;
int s[N], a[N], b[N], dp[N];
vector<int> v, ans;
vector<P> trc;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[b[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		int val = a[s[i]];
		if (v.empty() || v[cnt - 1] < val) {
			v.push_back(val);
			trc.push_back({ cnt, s[i] });
			cnt++;
		}
		else {
			for (int j = 0; j < cnt; j++) {
				if (v[j] >= val) {
					v[j] = val;
					trc.push_back({ j, s[i] });
					break;
				}
			}
		}
	}

	cnt--;
	for (int i = trc.size() - 1; i >= 0; i--) {
		if (trc[i].first != cnt) continue;
		ans.push_back(trc[i].second);
		cnt--;
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int prt : ans) printf("%d ", prt);

	return 0;
}