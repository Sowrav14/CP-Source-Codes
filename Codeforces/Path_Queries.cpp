#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
    Approach:
    - DFS assign tin[u] and tout[u] (subtree interval).
    - Use a Fenwick tree that supports range add and point query via
      add(l, delta); add(r+1, -delta); point_query(i) = prefix_sum(i).
    - Initialize by adding val[u] to range [tin[u], tout[u]] for every u.
    - Query type 2 (sum root->s): point_query(tin[s]).
    - Update type 1 (set s to x): delta = x - val[s]; add delta to [tin[s], tout[s]]; val[s]=x.
    - Complexity O((n+q) log n).
*/

int n,q;
vector<int> g[200005];
int tin[200005], tout[200005], timer = 1;
int val[200005];

struct Fenwick{
    int n;
    vector<int> bit;
    Fenwick(int n=0){
        this->n = n;
        bit.assign(n+5,0);
    }
    void init(int n_){
        n = n_;
        bit.assign(n+5,0);
    }
    void add_point(int i, int v){
        for(; i<=n; i += (i & -i)) bit[i] += v;
    }
    int sum_prefix(int i){
        int s = 0;
        for(; i>0; i -= (i & -i)) s += bit[i];
        return s;
    }
    void add_range(int l, int r, int v){
        if(l>r) return;
        add_point(l, v);
        add_point(r+1, -v);
    }
    int point_query(int i){
        return sum_prefix(i);
    }
};

void dfs(int u,int p){
    tin[u] = timer++;
    for(auto v: g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    tout[u] = timer-1;
}

void solve(){

    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> val[i];

    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    timer = 1;
    dfs(1,0);

    Fenwick fenw;
    fenw.init(n+5);

    for(int i=1;i<=n;i++){
        fenw.add_range(tin[i], tout[i], val[i]);
    }

    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int s,x;
            cin >> s >> x;
            int delta = x - val[s];
            val[s] = x;
            fenw.add_range(tin[s], tout[s], delta);
        } else {
            int s;
            cin >> s;
            cout << fenw.point_query(tin[s]) << endl;
        }
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
