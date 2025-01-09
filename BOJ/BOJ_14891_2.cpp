#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int k, n, d, ans;
int chk[4];
bool wheels[4][8];

void turnWheel(int n, int d) {

	if (d > 0) {
		bool tmp = wheels[n][7];
		for (int j = 7; j; j--) {
			wheels[n][j] = wheels[n][j - 1];
		}
		wheels[n][0] = tmp;
	}
	else if (d < 0) {
		bool tmp = wheels[n][0];
		for (int j = 0; j < 7; j++) {
			wheels[n][j] = wheels[n][j + 1];
		}
		wheels[n][7] = tmp;
	}
	else return;
}

void chkWheel(int cur, int dir) {

	if (dir > 0) {
		if (cur >= 3) return;
		if (wheels[cur][2] != wheels[cur + 1][6]) {
			chk[cur + 1] = chk[cur] > 0 ? -1 : 1;
			chkWheel(cur + 1, dir);
		}
	}
	else {
		if (cur <= 0) return;
		if (wheels[cur][6] != wheels[cur - 1][2]) {
			chk[cur - 1] = chk[cur] > 0 ? -1 : 1;
			chkWheel(cur - 1, dir);
		}
	}
}

int main(void) {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			if (getchar() == '1') wheels[i][j] = true;
		}
		getchar();
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &n, &d);

		memset(chk, false, sizeof(chk));
		n -= 1;
		chk[n] = d;
		chkWheel(n, -1);
		chkWheel(n, 1);

		for (int i = 0; i < 4; i++) {
			turnWheel(i, chk[i]);
		}
	}

	for (int i = 0; i < 4; i++) {
		if (wheels[i][0]) ans += pow(2, i);
	}
	printf("%d", ans);

	return 0;
}