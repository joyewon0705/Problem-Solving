#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, cnt = 10;
long long ans;
bool chk[10];
char str[13];
long long m[10];

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &str);
		chk[str[0] - 'A'] = true;
		long long k = 1;
		for (int j = strlen(str) - 1; j >= 0; j--) {
			if (m[str[j] - 'A'] == 0) cnt--;
			m[str[j] - 'A'] += k;
			k *= 10;
		}
	}

	if (cnt == 0) {
		int a;
		long long b = (long long)1 << 60;
		for (int i = 0; i < 10; i++) {
			if (chk[i]) continue;
			if (b > m[i]) {
				a = i;
				b = m[i];
			}
		}
		m[a] = 0;
	}

	sort(m, m + 10, greater<>());
	for (int i = 0, j = 9; i < 10; i++, j--) {
		ans += m[i] * j;
	}
	printf("%lld", ans);

	return 0;
}