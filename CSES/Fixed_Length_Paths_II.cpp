#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int>g[N];
int k1, k2;
int ans = 0;

// getprefix sum in a range.
int getPrefix(deque<int> &a, int mx){
    if(mx < 0) return 0;
    if(mx+1 >= a.size()) return a[0];
    return a[0] - a[mx + 1];
}


// merge two prefix sum array using small to large technique.
// also generate ans for the prefix sum arrays.
void merge(deque<int> &a, deque<int> &b){
    if(a.size() < b.size()) swap(a, b);

    for(int i=0;i<b.size()-1;i++) b[i] -= b[i+1];
    for(int i=0;i<b.size();i++){
        ans += b[i] * (getPrefix(a, k2-i) - getPrefix(a, k1-i-1));
    }

    for(int i=b.size()-2;i>=0;i--) b[i] += b[i+1];
    for(int i=0;i<b.size();i++) a[i] += b[i];
}

// each node contains a deque which stores the prefix sum...
deque<int> dfs(int u, int p){
    deque<int>du{1};
    for(auto v : g[u]){
        if(v == p) continue;
        deque<int> dv = dfs(v, u);
        dv.push_front(dv.front());
        merge(du, dv);
    }
    return du;
}


void solve(){

    cin >> n >> k1 >> k2;
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}