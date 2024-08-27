#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int a, b;
vector<P> points;

int ccw(P p1, P p2, P p3) {
	int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second
		- (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);

	if (s > 0) return 1;
	else if (s < 0) return -1;
	else return 0;
}

int main(void) {

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &a, &b);
		points.push_back({ a, b });
	}

	a = ccw(points[0], points[1], points[2]) * ccw(points[0], points[1], points[3]);
	b = ccw(points[2], points[3], points[0]) * ccw(points[2], points[3], points[1]);

	if (a < 0 && b < 0) printf("1");
	else printf("0");

	return 0;
}