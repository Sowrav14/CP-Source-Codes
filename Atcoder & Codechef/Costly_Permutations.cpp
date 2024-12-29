#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int>g[N];
int vis[N];
int sz;

void dfs(int u){
    vis[u] = 1;
    sz++;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        g[i].clear();
        vis[i] = 0;
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        g[i].push_back(x);
    }

    multiset<int>s;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sz = 0;
            dfs(i);
            s.insert(sz);
        }
    }

    int ans = 0;
    while(s.size() > 1){
        auto it = s.begin();
        auto itt = it;
        itt++;
        int x = *it;
        int y = *itt;
        int z = x + y;
        s.erase(it);
        s.erase(itt);
        s.insert(z);
        ans += z;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}