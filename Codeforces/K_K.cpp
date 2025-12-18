#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


const int MAXP = 65;

int pow2[MAXP];
int invpow2[MAXP];

// Fast modular exponentiation
int modpow(int a, int b, int mod){
    int res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precalc(){
    pow2[0] = 1;
    for(int i = 1; i < MAXP; i++) pow2[i] = (pow2[i-1]*2) % M;
    
    for(int i = 0; i < MAXP; i++){
        invpow2[i] = modpow(pow2[i], M-2, M); // Fermat's little theorem
    }
}



int par[N];
int val[N];
int sub[N][61];
vector<int> g[N];

void dfs(int u, int p){
    par[u] = p;
    for(auto v : g[u]){
        if(v != p) dfs(v, u);
    }
}

void solve(){
  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; i++){
    g[i].clear();
    val[i] = 0;
    for(int j = 0; j <= 60; j++) sub[i][j] = 0;
    par[i] = 0;
  }
  for(int i = 0; i < n-1; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);

  while(q--){
    int t; cin >> t;
    if(t == 1){
      int x, y; cin >> x >> y;
      // Ancestors
      int d = 0, u = x;
      while(d <= y){
        val[u] = (val[u] + (1LL << (y - d))) % M;
        if(u == 1) break;
        u = par[u];
        d++;
      }
      // sub
      for(int i = 1; i <= y; i++){
        sub[x][i] = (sub[x][i] + (1LL << (y - i))) % M;
      }
    } else {
      int x; cin >> x;
      int ans = val[x];
      int d = 1, u = par[x];
      while(d <= 60 && x != 1){
          ans = (ans + sub[u][d]) % M;
          if(u == 1) break;
          u = par[u];
          d++;
      }
      cout << ans << "\n";
    }
  }
}


signed main(){
  Fast_IO()
  int t = 1;
  precalc();
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}
