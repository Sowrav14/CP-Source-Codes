#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e5+10;
vector<int>g[N];
int st[N], fi[N];
int timer = 0;

double tree[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = 0;
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

void singleupdate(int node, int l, int r, int i, double val){

    if(l>i or r<i) return;
    if(l == r){
        tree[node] = log10(val);
        return;
    }

    int mid = (l + r) / 2;
    singleupdate(2*node, l, mid, i, val);
    singleupdate(2*node+1, mid+1, r, i, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

double query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return 0;
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    double left = query(2*node, l, mid, i, j);
    double right = query(2*node+1, mid+1, r, i, j);
    return left + right;
}


// dfs for euler tour
// calculate entering time end leaving time of each node...
void dfs(int u, int p){
    st[u] = ++timer;
    for(auto v : g[u]){
        if(v != p) dfs(v, u);
    }
    fi[u] = timer;
}


void solve(){

    int n; cin >> n;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    build(1, 1, n);
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            singleupdate(1, 1, n, st[x], y*1.0);
        } else{
            int x, y; cin >> x >> y;
            double fst = query(1, 1, n, st[x], fi[x]);
            double scd = query(1, 1, n, st[y], fi[y]);

            double ans = fst - scd;
            if(ans >= 9.00000){
                cout << 1000000000 << endl;
            } else{
                cout << fixed << setprecision(10) << pow(10, ans) << endl;
            }
        }
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}