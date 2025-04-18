#include <iostream>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 1010

typedef pair<int, int> P;

int n, m, u, v, w, cur;
bool chk[N];
int parents[N], cost[N];
vector<P> buses[N];

void printAnswer(int cur, int cnt) {

	if (parents[cur] == 0) printf("%d\n", cnt);
	else printAnswer(parents[cur], cnt + 1);
	printf("%d ", cur);
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		buses[u].push_back({ v, w });
	}
	scanf("%d %d", &u, &v);

	for (int i = 1; i <= n; i++) cost[i] = INF;

	cost[u] = 0;
	cur = u;
	while (cur != v) {
		chk[cur] = true;
		for (P bus : buses[cur]) {
			if (cost[bus.first] > cost[cur] + bus.second) {
				parents[bus.first] = cur;
				cost[bus.first] = cost[cur] + bus.second;
			}
		}

		int max = INF;
		for (int i = 1; i <= n; i++) {
			if (chk[i]) continue;
			if (max > cost[i]) {
				cur = i;
				max = cost[i];
			}
		}
	}

	printf("%d\n", cost[v]);
	printAnswer(v, 1);

	return 0;
}