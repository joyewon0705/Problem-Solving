#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 202

int ac, bc, cc;
bool chk[N], isVisit[N][N];
vector<int> v;

void f(int a, int b, int c) {

	if (a == 0) {
		if (chk[c]) return;
		chk[c] = true;
		v.push_back(c);
	}

	if (isVisit[b][c]) return;
	isVisit[b][c] = true;

	if (a) {
		if (a > bc - b) f(a - (bc - b), bc, c);
		else f(0, b + a, c);
		if (a > cc - c) f(a - (cc - c), b, cc);
		else f(0, b, c + a);
	}
	if (b) {
		if (b > ac - a) f(ac, b - (ac - a), c);
		else f(a + b, 0, c);
		if (b > cc - c) f(a, b - (cc - c), cc);
		else f(a, 0, c + b);
	}
	if (c) {
		if (c > ac - a) f(ac, b, c - (ac - a));
		else f(a + c, b, 0);
		if (c > bc - b) f(a, bc, c - (bc - b));
		else f(a, b + c, 0);
	}
}

int main(void) {

	scanf("%d %d %d", &ac, &bc, &cc);

	f(0, 0, cc);

	sort(v.begin(), v.end());

	for (int ans : v) printf("%d ", ans);

	return 0;
}