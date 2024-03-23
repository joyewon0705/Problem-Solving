#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define N 2020202

bool ans;
int t;
long long a, b, sum;
bool isPrime[N];
vector<int> primes;

int main(void) {

	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; i++) {
		if (isPrime[i])
			for (int j = i * i; j < N; j += i) isPrime[j] = false;
	}

	for (int i = 2; i < N; i++)
		if (isPrime[i]) primes.push_back(i);

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%lld %lld", &a, &b);

		ans = true;
		sum = a + b;
		if (sum < 4) ans = false;
		else if (sum % 2) {
			sum -= 2;

			for (int p : primes) {
				if ((long long)p * p > sum) break;
				if (sum % p == 0) {
					ans = false;
					break;
				}
			}
		}

		if (ans) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}