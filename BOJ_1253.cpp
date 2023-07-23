#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
long long a, low, high, val, tmp;
vector<long long> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		val = v[i];

		low = 0; high = n - 1;
		while (low < high) {
			if (low == i) {
				low++; continue;
			}
			if (high == i) {
				high--; continue;
			}
			tmp = v[low] + v[high];
			if (val > tmp) low++;
			else if (val < tmp) high--;
			else {
				ans++;
				break;
			}
		}
	}

	printf("%d", ans);

	return 0;
}