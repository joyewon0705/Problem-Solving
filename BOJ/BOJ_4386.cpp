#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define N 101
typedef pair<double, int> P;

int n;
double x, y, ans;
bool chk[N];
vector<pair<double, double>> v;
priority_queue<P, vector<P>, greater<P>> pq;

double distance(int x, int y) {
	double a = pow(v[x].first - v[y].first, 2);
	double b = pow(v[x].second - v[y].second, 2);
	return sqrt(a + b);
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		v.push_back({ x, y });
	}

	pq.push({ 0, 0 });
	while (!pq.empty()) {
		double dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (chk[cur]) continue;
		chk[cur] = true;
		ans += dist;

		for (int i = 0; i < n; i++) {
			if (chk[i]) continue;
			pq.push({ distance(cur, i), i });
		}
	}

	printf("%lf", ans);

	return 0;
}