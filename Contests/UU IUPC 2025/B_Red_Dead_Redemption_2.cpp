#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5e6 + 10;
const int M = 998244353;
const int inf = 1e12;

// sieve with smallest prime factors (spf)
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
}

vector<vector<int>> m(N);
vector<int> primes;

void solve(){

    int n; cin >> n;
    
    for(auto p : primes) m[p].clear();
    primes.clear();

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        while (x > 1) {
            int p = spf[x];
            if(m[p].empty()) primes.push_back(p);
            m[p].push_back(i);
            while(x % p == 0) x /= p;
        }
    }

    vector<vector<int>> g(n+1);
    for(auto p : primes){
        if(m[p].size() > 2){
            cout << 0 << endl;
            return;
        }
        if(m[p].size() == 2){
            int u = m[p][0];
            int v = m[p][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    vector<int> vis(n+1, 0), color(n+1, -1);
    function <bool(int, int, int)> dfs = [&](int u, int p, int c) -> bool {
        vis[u] = 1;
        color[u] = c;
        bool ret = true;
        for(auto v : g[u]){
            if(!vis[v]) ret &= dfs(v, u, 1 - c);
            if(color[v] == c and v != p) ret = false;
        }
        return ret;
    };

    int cnt = 0, ok = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            ok &= dfs(i, -1, 0);
        }
    }
    if(!ok) return cout << 0 << endl, void();
    // cout << cnt << endl;
    int ans = 1;
    for(int i=1;i<=cnt;i++){
        ans = (2ll * ans) % M;
    }
    if(cnt == n) ans = (ans - 2 + M)%M;

    cout << ans << endl;

}


signed main(){
    Fast_IO()
    sieve();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}