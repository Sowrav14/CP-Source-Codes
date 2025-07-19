#include <iostream>
using namespace std;

const int MOD = 998244353;

int main() {
    long long n;
    cin >> n;

    // Safe computation of total = n*(n-1)/2 % MOD
    long long total = n % MOD;
    total = total * ((n - 1) % MOD) % MOD;
    total = total * ((MOD + 1) / 2) % MOD; // 2^(-1) mod MOD

    // Count invalid (a, b) where a % b == 0
    long long bad = 0;
    for (long long l = 1; l <= n;) {
        long long q = n / l;
        long long r = n / q + 1;

        long long cnt = r - l;
        bad = (bad + cnt % MOD * (q - 1) % MOD) % MOD;

        l = r;
    }

    long long ans = (total - bad + MOD) % MOD;
    cout << ans << endl;

    return 0;
}
