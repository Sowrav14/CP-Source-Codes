#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

bool is_prime[N];
vector<int> primes;
void sieve_v0() {
    for (int i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int spf[N];
void sieve() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }
}

int a[N];

int countDivisible(vector<int>& arr) {
    int n = arr.size();
    int odd = 0, even = 0;

    // Total subsets = 2^n (including empty set)
    int powerset = (1 << n);

    // Iterate through all non-empty subsets of primes
    for (int i = 1; i < powerset; i++) {
        int p = 1;

        // Compute the product of selected primes in this subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                p *= arr[j];

                // If product exceeds m, break early
                if (p >= N)
                    break;
            }
        }

        // If product exceeds m, skip this subset
        if (p >= N)
            continue;

        // Inclusion-Exclusion:
        // - If the number of selected primes is odd, add the count
        // - If even, subtract the count
        if (__builtin_popcount(i) & 1)
            odd += a[p];   
        else
            even += a[p];  
    }

    // Final result based on Inclusion-Exclusion Principle
    return odd - even;
}

// Function to get unique prime factors using precomputed SPF
vector<int> primeFac(int n) {
    set<int> uniqueFactors;
    while (n > 1) {
        uniqueFactors.insert(spf[n]);
        n /= spf[n];
    }
    return vector<int>(uniqueFactors.begin(), uniqueFactors.end());
}

int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%M * a%M) % M;
        }
        a = (1ll * a%M * a%M) % M;
        b >>= 1;
    }
    return ret;
}


void solve(){

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        for(int j=1;j*j<=x;j++){
            if(x%j == 0) {
                a[j]++;
                if((x/j) != j) a[x/j]++; 
            }
        }
    }

    // for(int i=1;i<=6;i++) cout << a[i] << " "; cout << endl;

    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int x; cin >> x;
        vector<int> pfact = primeFac(x);
        // for(auto i : pfact) cout << i << " "; cout << endl;
        int y = countDivisible(pfact);
        y = n - y;
        cout << A_pow_B(2, y) << endl;
    }

}


signed main(){
    Fast_IO()
    sieve_v0();
    sieve();
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}