#include <iostream>
#include <cmath>
using namespace std;

typedef struct _gear {
	int left, right;
	bool s[8];
}_gear;

int k, a, b, ans;
_gear gears[5];

void turnGear(int idx, int dir) {
	int nl, nr;

	if (dir > 0) {
		nl = (gears[idx].left + 7) % 8;
		nr = (gears[idx].right + 7) % 8;
	}
	else if (dir < 0) {
		nl = (gears[idx].left + 1) % 8;
		nr = (gears[idx].right + 1) % 8;
	}
	gears[idx].left = nl;
	gears[idx].right = nr;
}

void execute(int idx, int dir, int next) {
	int nd = dir > 0 ? -1 : 1;

	if (next > 0 && idx < 4) {
		if (gears[idx].s[gears[idx].right] != gears[idx + 1].s[gears[idx + 1].left])
			execute(idx + 1, nd, 1);
	}
	else if (next < 0 && idx > 1) {
		if (gears[idx].s[gears[idx].left] != gears[idx - 1].s[gears[idx - 1].right])
			execute(idx - 1, nd, -1);
	}

	turnGear(idx, dir);
}

int main(void) {

	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (getchar() == '1') gears[i].s[j] = true;
			else gears[i].s[j] = false;
			gears[i].left = 6;
			gears[i].right = 2;
		}
		while (getchar() != '\n');
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		
		int nb = b > 0 ? -1 : 1;
		if (a < 4 && gears[a].s[gears[a].right] != gears[a + 1].s[gears[a + 1].left]) execute(a + 1, nb, 1);
		if (a > 1 && gears[a].s[gears[a].left] != gears[a - 1].s[gears[a - 1].right]) execute(a - 1, nb, -1);
		turnGear(a, b);
	}

	for (int i = 1; i < 5; i++) {
		if (gears[i].s[(gears[i].left + 2) % 8]) 
			ans += pow(2, i - 1);
	}
	printf("%d", ans);

	return 0;
}