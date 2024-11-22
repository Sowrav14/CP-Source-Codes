#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;

// calculate (a^b) % mod
int power(long long n, long long k, const int mod) {
    int ans = 1 % mod;
    n %= mod;
    if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = ans * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}

// define mods and calculate powers and inverse_powers...
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];

void prec() {
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}


struct Hashing {
    int n;
    string s; // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    // get hash from (l...r)
    pair<int, int> get_hash(int l, int r) { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    // get hash from (1...n)
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};

struct BIT {
	int size;
    int mod;
	vector<int> bit;
	BIT(int n, int mod) : size(n), mod(mod), bit(n + 10) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] = (val%mod + bit[idx]%mod)%mod;
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum = (sum%mod + bit[idx]%mod)%mod;
            idx -= (idx) & (-idx);
        }
        return sum;
    }
    // update the value at [l...r] by val.
    void update(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
    // sum form [l...r]
    int query(int l, int r){
        return (query(r)%mod - query(l-1)%mod + mod)%mod;
    }
};

void solve(){

    int n,q; cin >> n >> q;
    string s; cin >> s;

    BIT bit1(n, MOD1), bit2(n, MOD2), rbit1(n, MOD1), rbit2(n, MOD2);

    for(int i=0;i<n;i++){
        int h1 = (pw[i].first%MOD1 * s[i]%MOD1)%MOD1;
        int h2 = (pw[i].second%MOD2 * s[i]%MOD2)%MOD2;

        bit1.update(i+1, h1);
        bit2.update(i+1, h2);
    }

    for(int i=0, j=n-1;i<n;i++, j--){
        int h1 = (pw[i].first%MOD1 * s[j]%MOD1)%MOD1;
        int h2 = (pw[i].second%MOD2 * s[j]%MOD2)%MOD2;

        rbit1.update(i+1, h1);
        rbit2.update(i+1, h2);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            char c; cin >> c;

            int id = x - 1;
            int rid = n - id - 1;

            int h1 = (pw[id].first%MOD1 * (c - s[id])%MOD1)%MOD1;
            int h2 = (pw[id].second%MOD2 * (c - s[id])%MOD2)%MOD2;
            int rh1 = (pw[rid].first%MOD1 * (c - s[id])%MOD1)%MOD1;
            int rh2 = (pw[rid].second%MOD2 * (c - s[id])%MOD2)%MOD2;

            s[id] = c;

            bit1.update(id+1, h1);
            bit2.update(id+1, h2);
            rbit1.update(rid+1, rh1);
            rbit2.update(rid+1, rh2);
        } else{
            int l, r; cin >> l >> r;
            int a = (bit1.query(l, r)%MOD1 * ipw[l-1].first%MOD1)%MOD1;
            int b = (bit2.query(l, r)%MOD2 * ipw[l-1].second%MOD2)%MOD2;
            int ra = (rbit1.query(n-r+1, n-l+1)%MOD1 * ipw[n-r].first%MOD1)%MOD1;
            int rb = (rbit2.query(n-r+1, n-l+1)%MOD2 * ipw[n-r].second%MOD2)%MOD2;

            if(a == ra and b == rb){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

}


signed main(){
    Fast_IO()
    prec();
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

/*

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 127657753;
int B = 137; //Sheldon prime (lol)
const int mxN = 1e6+6;
int pB[mxN];
struct {
    int bit[mxN] = {0};

    void update(int k, int x) {
        x %= md;
        if (x < md) x += md;
        for (; k < mxN; k += k&-k) {
            (bit[k] += x) %= md;
        }
    }

    int query(int k) {
        int s = 0;
        for (; k > 0; k -= k&-k)
            (s += bit[k]) %= md;
        return s;
    }
} pre, suf;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // B = uniform_int_distribution<int>(73, 7337)(rng);
    
    int n, t; cin>>n>>t;
    string s; cin>>s;
    pB[0] = 1;
    for (int i = 1; i < mxN; i++) 
        pB[i] = pB[i-1] * B % md;

    for (int i = 0; i < n; i++) {
        pre.update(i+1, (s[i]-'a'+1) * pB[i]);
        suf.update(i+1, (s[i]-'a'+1) * pB[n-i-1]);
    }
    while (t--) {
        int ch; cin>>ch;
        if (ch == 1) {
            int k; char x;
            cin>>k>>x; k--;
            pre.update(k+1, -(s[k]-'a'+1) * pB[k]);
            pre.update(k+1, (x-'a'+1) * pB[k]);
            suf.update(k+1, -(s[k]-'a'+1) * pB[n-k-1]);
            suf.update(k+1, (x-'a'+1) * pB[n-k-1]);
            s[k] = x;
        }
        else {
            int x, y; cin>>x>>y;
            int h1 = (pre.query((x+y)/2) - pre.query(x-1) + md) % md;
            int m1 = pB[x-1];
            int h2 = (suf.query(y) - suf.query((x+y-1)/2) + md) % md;
            int m2 = pB[n-y];
            cout << (h1 * m2 % md == h2 * m1 % md ? "YES" : "NO" ) << endl;            
        }
    }
}

 */