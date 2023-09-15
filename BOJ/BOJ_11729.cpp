#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int n, k;
vector<P> v;

void move(int c, int st, int ed, int tm) {

	if (c == 1) {
		v.push_back({ st, ed });
		k++;
		return;
	}

	move(c - 1, st, tm, ed);
	move(1, st, ed, tm);
	move(c - 1, tm, ed, st);
}

int main(void) {

	scanf("%d", &n);

	move(n, 1, 3, 2);

	printf("%d\n", k);
	for (P prt : v) printf("%d %d\n", prt.first, prt.second);

	return 0;
}