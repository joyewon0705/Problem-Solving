#include <iostream>
#include <vector>
using namespace std;

#define N 40404

int n, ans;
int a[N];
vector<int> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	v.push_back(a[1]);
	for (int i = 2; i <= n; i++) {
		bool chk = false;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] > a[i]) {
				v[j] = a[i];
				chk = true;
				break;
			}
		}
		if (!chk) v.push_back(a[i]);
	}

	printf("%d", v.size());

	return 0;
}