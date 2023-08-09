#include <iostream>
#include <queue>
using namespace std;

int n, in;
long long ans;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		pq.push(in);
	}

	while (pq.size() > 1) {
		long long tmp = pq.top(); pq.pop();
		tmp += pq.top(); pq.pop();
	
		ans += tmp;
		pq.push(tmp);
	}

	printf("%lld", ans);

	return 0;
}