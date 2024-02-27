#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define N 5050

int n, ans;
char a[N];

int f(char *a) {
	int n = strlen(a), ret = 0;
	vector<int> v = { 0 };

	for (int i = 1, j = 0; i < n; i++) {
		while (j && a[i] != a[j]) j = v[j - 1];
		if (a[i] == a[j]) {
			v.push_back(++j);
			ret = max(ret, v[i]);
		}
		else v.push_back(0);
	}
	return ret;
}

int main(void) {

	scanf("%s", a);

	n = strlen(a);
	for (int i = 0; i < n; i++) {
		ans = max(ans, f(&a[i]));
	}

	printf("%d", ans);

	return 0;
}