#include <iostream>
#include <vector>
using namespace std;

int n, a, low, mid, high;
vector<int> chk;

int main(void) {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);

		if (chk.empty() || chk[chk.size() - 1] < a) chk.push_back(a);
		else {
			low = 0; high = chk.size() - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (chk[mid] < a) low = mid + 1;
				else high = mid - 1;
			}
			chk[low] = a;
		}
	}
	
	printf("%d", chk.size());

	return 0;
}