#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
const int N = 5000 + 10;
const int M = 1e9 + 7;

vector<int> primes{0};
bool is_prime[N];
void sieve() {
    for (int i = 0; i < N; i++) is_prime[i] = false;
    if (N>2) for (int i = 2; i < N; i++) is_prime[i] = true;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) is_prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++) if (is_prime[i]) primes.push_back(i);
}

void solve(){
    int n,k;
    cin >> n >> k;

    // dp positions: 0 (start) .. n+1 (end). answer = dp[n+1]
    vector<int> dp(n + 2, 0);
    dp[0] = 1;

    for (int i = 0; i <= n; i++) {
        if (!dp[i]) continue;
        for (int p : primes) {
            if (p > k - 1) break;         // hole size p requires jump p+1 <= k -> p <= k-1
            int nxt = i + p + 1;         // move from position i to i+(p+1)
            if (nxt > n + 1) break;
            dp[nxt] = (dp[nxt] + dp[i]) % M;
        }
    }

    cout << dp[n + 1] % M << endl;
}

signed main(){
    Fast_IO()
    sieve();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
