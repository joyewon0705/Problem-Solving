#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<int> v, m, h;

int getNext(int cur, int val) {
	int next = cur;

	if (cur == 5) { next = 22; val--; }
	else if (cur == 10) { next = 31; val--; }
	else if (cur == 15) { next = 28; val--; }

	while (val--) {
		if (next == 27) next = 20;
		else if (next == 32 || next == 30) next = 25;
		else next++;
		if (next == 21) break;
	}

	return next;
}

void f(int cur, int cnt) {

	if (cur >= 10) {
		if (ans < cnt) ans = cnt;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (h[i] == 21) continue;

		int next = getNext(h[i], v[cur]);

		if (next != 21) {
			for (int j = 0; j < 4; j++) {
				if (h[j] == next) {
					next = 0;
					break;
				}
			}
		}
		if (next) {
			int tmp = h[i];
			h[i] = next;
			f(cur + 1, cnt + m[next]);
			h[i] = tmp;
		}
	}
}

int main(void) {

	m = vector<int>(33, 0);
	for (int i = 0; i < 21; i++) m[i] = 2 * i;
	m[22] = 13; m[23] = 16; m[24] = 19;
	m[25] = 25; m[26] = 30; m[27] = 35;
	m[28] = 28; m[29] = 27; m[30] = 26;
	m[31] = 22; m[32] = 24;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}

	h = vector<int>(4, 0);
	f(0, 0);

	printf("%d", ans);

	return 0;
}