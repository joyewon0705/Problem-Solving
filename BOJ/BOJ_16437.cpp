#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 123458

int n, t, a, p;
int anm[N];
vector<int> v[N];

long long f(int cur) {
	long long ret = anm[cur];

	for (int next : v[cur]) {
		ret += f(next);
	}
	if (ret < 0) ret = 0;
	return ret;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		getchar();
		scanf("%c %d %d", &t, &a, &p);
		if (t == 'S') anm[i] = a;
		else anm[i] = -a;
		v[p].push_back(i);
	}
	printf("%lld", f(1));

	return 0;
}