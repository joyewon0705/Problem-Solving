#include <iostream>
#include <vector>
using namespace std;

#define N 11

int n, a, b, p, q, gcd, na, nb;
bool isVisit[N];
int m[N];
vector<int> v[N];

int getGcd(int a, int b) {
	if (b) return getGcd(b, a % b);
	else return a;
}

void f(int a, int b) {
	m[a] *= b;
	isVisit[a] = true;
	for (int next : v[a]) {
		if (!isVisit[next]) f(next, b);
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) m[i] = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &p, &q);
		gcd = getGcd(p, q);
		na = m[b] * p / gcd;
		nb = m[a] * q / gcd;
		gcd = getGcd(na, nb);
		for (int i = 0; i < n; i++) isVisit[i] = false;
		f(a, na / gcd);
		f(b, nb / gcd);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) printf("%d ", m[i]);

	return 0;
}