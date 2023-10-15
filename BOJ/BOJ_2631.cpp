#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);

		bool chk = false;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] > m) {
				v[j] = m;
				chk = true;
				break;
			}
		}
		if (!chk) v.push_back(m);
	}
	printf("%d", n - v.size());

	return 0;
}