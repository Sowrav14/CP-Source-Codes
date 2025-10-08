#include <bits/stdc++.h>
using namespace std;

long long minCost(long long n) {
    long long cost = 0;
    long long p = 1;
    while ((p << 1) <= n) {
        cost += p;   // add current power of 2
        p <<= 1;     // move to next power of 2
    }
    cost += (n - p);  // add remainder
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        cout << minCost(N) << "\n";
    }
    return 0;
}
