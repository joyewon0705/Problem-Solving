#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, s, t;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> list;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &t);
		list.push_back({ s, t });
	}

	sort(list.begin(), list.end());

	pq.push(list[0].second);
	for (int i = 1; i < n; i++) {
		if (pq.top() <= list[i].first) pq.pop();
		pq.push(list[i].second);
	}

	printf("%d", pq.size());

	return 0;
}