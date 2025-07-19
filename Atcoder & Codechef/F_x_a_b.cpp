#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> getPrimeFactors(ll x) {
    vector<ll> factors;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }
    if (x > 1) factors.push_back(x);
    return factors;
}

ll safePower(ll a, ll b) {
    ll result = 1;
    for (ll i = 0; i < b; i++) {
        double dres = result;
        dres *= a;
        if (dres > 2e18) return 2e18;
        result *= a;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll total = 0;

    for (ll b = 2; b < 60; b++) {
        ll left = 2, right = 2e9;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (safePower(mid, b) > n) right = mid - 1;
            else left = mid + 1;
        }
        ll maxA = right;
        vector<ll> primes = getPrimeFactors(b);
        bool hasSquare = false;
        for (ll i = 1; i < primes.size(); i++) {
            if (primes[i - 1] == primes[i]) {
                hasSquare = true;
                break;
            }
        }
        if (hasSquare) continue;
        ll count = maxA - 1;
        if (primes.size() % 2) total += count;
        else total -= count;
    }

    cout << total + 1 << "\n";

    return 0;
}