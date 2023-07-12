#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, in;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &in);

		if (min_pq.size() == max_pq.size()) max_pq.push(in);
		else min_pq.push(in);

		if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
			int max_val = max_pq.top(); max_pq.pop();
			int min_val = min_pq.top(); min_pq.pop();
			
			max_pq.push(min_val);
			min_pq.push(max_val);
		}
		printf("%d\n", max_pq.top());
	}

	return 0;
}