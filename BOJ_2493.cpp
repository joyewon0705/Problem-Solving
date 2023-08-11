#include <iostream>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 505050

int n;
int h[N] = { INF };
vector<int> v = { 0 };

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			if (h[i] <= h[v[j]]) {
				printf("%d ", v[j]);
				break;
			}
		}
		if (h[v[v.size() - 1]] <= h[i])
			v[v.size() - 1] = i;
		else v.push_back(i);
	}

	return 0;
}