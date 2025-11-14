#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
 
int n, q;
int c[N];
vector<int>g[N];
vector<pair<int, int>> qu[N];
int ans[N];

#define ordered_set         tree<int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).
ordered_set sub[N];
// ordered_set ssub[N];
 
void dfs(int u, int p){
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        if(sub[u].size() < sub[v].size()) sub[u].swap(sub[v]);
        for(auto col : sub[v]){
            sub[u].insert(col);
        }
    }
    // ssub[u] = sub[u];
    for(auto query : qu[u]){
        int x = query.first;
        int id = query.second;
        int res = sub[u].size() - sub[u].order_of_key(x);
        ans[id] = res;
    }
}



 
void solve(){
 
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int p; cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    for(int i=1;i<=n;i++) {
        cin >> c[i];
        sub[i].insert(c[i]);
    }
    
    
    // for(int i=1;i<=n;i++){
    //     cout << ssub[i].size() - ssub[i].order_of_key (5) << endl;
    // }
    for(int i=1;i<=q;i++){
        int v, x; cin >> v >> x;
        qu[v].push_back({x, i});

        // cout << ssub[v].size() - ssub[v].order_of_key(x) << endl;
    }
    dfs(1, 0);
    for(int i=1;i<=q;i++){
        cout << ans[i] << endl;
    }
 
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