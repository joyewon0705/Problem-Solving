#include <iostream>
#include <queue>
using namespace std;

#define N 101

int n, k, l, ans;
bool chk[N];
int m[N], plug[N];
queue<int> q[N];

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &m[i]);
		q[m[i]].push(i);
	}

	for (int i = 1; i <= k; i++) {
		int cur = m[i];

		q[cur].pop();
		if (chk[cur]) continue;
		else if (l < n) {
			plug[l++] = cur;
			chk[cur] = true;
		}
		else {
			int tmp = 0;
			if (!q[plug[tmp]].empty()) {
				for (int j = 1; j < n; j++) {
					if (q[plug[j]].empty()) {
						tmp = j;
						break;
					}
					if (q[plug[tmp]].front() < q[plug[j]].front()) tmp = j;
				}
			}
			chk[plug[tmp]] = false;
			plug[tmp] = cur;
			chk[cur] = true;
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}