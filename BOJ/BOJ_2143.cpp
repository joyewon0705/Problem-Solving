#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1010

int t, n, m, a, b, maxA, maxB;
long long ans;
vector<int> A, B;

int main(void) {

	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		for (int j = 1; j <= i; j++) A.push_back(A[maxA - j] + a);
		A.push_back(a);
		maxA = A.size();
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b);
		for (int j = 1; j <= i; j++) B.push_back(B[maxB - j] + b);
		B.push_back(b);
		maxB = B.size();
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	a = 0; b = maxB - 1;
	while (a < maxA && b >= 0) {
		int val = A[a] + B[b];
		if (val < t) a++;
		else if (val > t) b--;
		else {
			int i = 1, j = 1;
			while (a + i < maxA && A[a] == A[a + i]) i++;
			while (b - j >= 0 && B[b] == B[b - j]) j++;
			ans += (long long)i * j;
			a += i; 
			b -= j;
		}
	}

	printf("%lld", ans);

	return 0;
}