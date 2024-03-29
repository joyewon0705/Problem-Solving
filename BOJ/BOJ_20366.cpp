#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 606

int n, h, ans;
vector<int> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		v.push_back(h);
	}

	sort(v.begin(), v.end());

	ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int a = v[i] + v[j];

			int low = i + 1, high = j - 1;
			while (low < high) {
				int b = v[low] + v[high];
				ans = min(ans, abs(a - b));

				if (a < b) high--;
				else low++;
			}
		}
	}

	printf("%d", ans);

	return 0;
}