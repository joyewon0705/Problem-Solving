#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000

unsigned long long n;
int m = 2;
vector<int> v = { 0, 1, 1 };

int main(void) {

	scanf("%llu", &n);

	while (true) {
		m++;
		int cur = (v[m - 1] + v[m - 2]) % MOD;
		if (v[m - 1] == 1 && cur == 0) break;
		v.push_back(cur);
	}

	printf("%d", v[n % m]);

	return 0;
}