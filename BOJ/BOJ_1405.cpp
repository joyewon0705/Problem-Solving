#include <iostream>
#include <cmath>
using namespace std;

#define N 30
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;
double sum;
bool chk[N][N];
double r[4];

void f(int x, int y, double cur, int cnt) {

	if (chk[x][y]) return;
	chk[x][y] = true;

	if (cnt == n) sum += cur;
	else if (cnt < n) {
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			f(nx, ny, cur * r[k], cnt + 1);
		}
	}

	chk[x][y] = false;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &m);
		r[i] = m / 100.0;
	}

	f(n, n, 1, 0);
	
	printf("%.10f", sum);

	return 0;
}