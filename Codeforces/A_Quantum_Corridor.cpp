#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// floor_sum from AtCoder Library
long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += (n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }
        long long y_max = a * n + b;
        if (y_max < m) break;
        n = y_max / m;
        b = y_max % m;
        swap(m, a);
    }
    return ans;
}

// Solve first collision: smallest k >= 1 where (S + kD) mod a in [L, R]
long long first_collision(long long a, long long D, long long S, long long L, long long R) {
    // Shift so target interval starts at 0
    long long l = (L - S) % a;
    if (l < 0) l += a;
    long long r = (R - S) % a;
    if (r < 0) r += a;

    if (l <= r) {
        // No wrap: find smallest k with kD mod a in [l, r]
        long long t = (r) / D;
        long long k = (l + D - 1) / D;
        if (k <= t) return k;
    }

    // Wrap-around interval => recurse using Euclid idea
    if (D == 0) return LLONG_MAX;
    return first_collision(D, a % D, S % D, l % D, r % D);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while(Q--){
        long long n,i,a,b;
        cin >> n >> i >> a >> b;

        if(a > b) swap(a,b);
        long long S = (i - 1) % a;     // start residue
        long long D = b % a;           // residue jump
        
        // Case 1: Wide corridor
        if(n >= a + b){
            long long g = __gcd(a,b);
            long long cnt = 0;
            // Count numbers x in [1,n] such that (x-1)%a ≡ S mod g
            long long r = (S % g);
            // First valid index
            long long first = 1 + ( ( (r - ((1-1)%a)%g ) % g + g ) % g );
            if(first <= n){
                cnt = 1 + (n - first) / g;
            }
            long long unreachable = n - cnt;
            cout << unreachable << "\n";
            continue;
        }

        // Case 2: Narrow corridor (n < a + b)
        long long L = n - b;   // forbidden start (inclusive)
        long long R = a - 1;   // forbidden end

        // Search forward and backward
        long long kf = first_collision(a, D, S, L, R);
        long long kb = first_collision(a, D, (a - S) % a, L, R);

        long long cycle = a / __gcd(a, D);
        long long K = min(cycle, kf + kb + 1);

        // Count physical chambers
        long long q = (n - 1) / a;
        long long r = (n - 1) % a;

        long long total = K * q;

        // How many reachable residues are ≤ r?
        long long count_le_r =
            floor_sum(K, a, D, S + a) - floor_sum(K, a, D, S + a - (r + 1));

        total += count_le_r;

        cout << (n - total) << "\n";
    }
    return 0;
}
