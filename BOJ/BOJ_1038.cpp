#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, cnt = -1;
vector<int> v[2][10];

int main(void) {

	scanf("%d", &n);

	if (n == 1022) printf("9876543210");
	else if (n > 1022) printf("-1");
	else {
		for (int j = 0; j < 10; j++) {
			v[1][j].push_back(j);
			cnt++;
			if (cnt == n) {
				printf("%d", j);
				return 0;
			}
		}

		for (int i = 2; i < 10; i++) {
			int cur = i % 2;
			int before = (i - 1) % 2;
			int digit = pow(10, (i - 1));
			for (int j = 0; j < 10; j++) {
				v[cur][j] = vector<int>();
				for (int k = 0; k < j; k++) {
					for (int num : v[before][k]) {
						v[cur][j].push_back(j * digit + num);
						cnt++;
						if (cnt == n) {
							printf("%d", j * digit + num);
							return 0;
						}
					}
				}
			}
		}
	}

	return 0;
}