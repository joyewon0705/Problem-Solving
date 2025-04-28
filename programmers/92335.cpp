#include <string>
#include <vector>

using namespace std;

bool isPrime(long long n) {
    
    if (n < 2) return false;
    if (n > 2 && n % 2 == 0) return false;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string s = "";
    while (true) {
        if (n % k) {
            s = to_string(n % k) + s;
        }
        else {
            if (s.size() && isPrime(stoll(s))) answer++; 
            s = "";
        }
        if (n < k) {
            if (s.size() && isPrime(stoll(s))) answer++; 
            break;
        }
        n /= k;
    }
    
    return answer;
}