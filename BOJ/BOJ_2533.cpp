#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1010101

int n, a, b;
bool isVisit[N];
int dp[N][2];
vector<int> v[N];

void f(int cur) {
	
	isVisit[cur] = true;
	dp[cur][1] = 1;
	for (int next : v[cur]) {
		if (isVisit[next]) continue;
		f(next);
		dp[cur][0] += dp[next][1];
		dp[cur][1] += min(dp[next][0], dp[next][1]);
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	f(1);

	printf("%d", min(dp[1][0], dp[1][1]));

	return 0;
}