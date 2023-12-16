#include <iostream>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 3030

int n, a, b; 
bool chk[N];
int d[N];
vector<int> v[N];

int findCircular(int cur, int before) {

	if (chk[cur]) return cur;
	chk[cur] = true;

	int ret = 0;
	for (int next : v[cur]) {
		if (next == before) continue;
		if (ret = findCircular(next, cur)) break;
	}
	if (ret) d[cur] = 0;
	if (ret == cur) ret = 0;
	return ret;
}

int f(int cur, int before) {

	if (d[cur] < INF) return d[cur];
	
	for (int next : v[cur]) {
		if (next == before) continue;
		d[cur] = f(next, cur) + 1;
		if (d[cur] < INF) break;
	}
	return d[cur];
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		d[i] = INF;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	findCircular(1, 0);
	for (int i = 1; i <= n; i++)
		if (v[i].size() == 1) f(i, 0);

	for (int i = 1; i <= n; i++) 
		printf("%d ", d[i]);

	return 0;
}