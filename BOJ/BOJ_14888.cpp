#include <iostream>

#define INF (ll)1<<60

typedef long long ll;

int n;
ll min = INF, max = -INF;
int operands[11], operators[4];

void f(int cur, ll val) {

	if (cur == n) {
		if (min > val) min = val;
		if (max < val) max = val;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i]) {
			operators[i]--;

			ll nval = val;
			if (i == 0) nval += operands[cur];
			else if (i == 1) nval -= operands[cur];
			else if (i == 2) nval *= operands[cur];
			else nval /= operands[cur];

			f(cur + 1, nval);

			operators[i]++;
		}
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &operands[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &operators[i]);
	}

	f(1, operands[0]);

	printf("%d\n%d", max, min);

	return 0;
}