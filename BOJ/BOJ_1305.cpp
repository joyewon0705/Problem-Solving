#include <iostream>
#include <string>
#include <vector>
using namespace std;

int l, n;
string a;
vector<int> v;

int main(void) {

	cin >> l;
	cin >> a;

	n = a.length();
	v = vector<int>(n, 0);
	for (int i = 1, j = 0; i < n; i++) {
		while (j && a[i] != a[j]) j = v[j - 1];
		if (a[i] == a[j]) v[i] = ++j;
	}

	cout << l - v[n - 1];

	return 0;
}