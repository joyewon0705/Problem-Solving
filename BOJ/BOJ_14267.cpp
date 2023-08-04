#include <iostream>
#include <vector>
using namespace std;

#define N 101010

int n, m, i, w;
int W[N];
vector<int> v[N];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int j = 1; j <= n; j++) {
		scanf("%d", &i);
		if (i < 0) continue;
		v[i].push_back(j);
	}
	for (int j = 0; j < m; j++) {
		scanf("%d %d", &i, &w);
		W[i] += w;
	}

	for (int i = 2; i <= n; i++) {
		if (W[i]) {
			for (int next : v[i])
				W[next] += W[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", W[i]);
	}


	return 0;
}