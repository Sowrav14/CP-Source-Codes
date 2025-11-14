#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 5e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
 
int n, q;
vector<int>g[N];
int a[N];
 
 

const int MAXV = 1000000 + 200000 + 10;
struct Node { 
    int l, r, sum; 
};
const int MAXNODE = 12000010;
Node seg[MAXNODE];
int root[N], idx = 0;

int update(int prev, int s, int e, int pos){
    int cur = ++idx;
    seg[cur] = seg[prev];
    seg[cur].sum++;
    if(s == e) return cur;
    int mid = (s + e) >> 1;
    if(pos <= mid) seg[cur].l = update(seg[prev].l, s, mid, pos);
    else seg[cur].r = update(seg[prev].r, mid + 1, e, pos);
    return cur;
}

int kth_missing(int u, int v, int s, int e, int k){
    if(s == e) return s;
    int mid = (s + e) >> 1;
    int left_count = seg[ seg[v].l ].sum - seg[ seg[u].l ].sum;
    int left_len = mid - s + 1;
    int missing_left = left_len - left_count;
    if(k <= missing_left) return kth_missing(seg[u].l, seg[v].l, s, mid, k);
    else return kth_missing(seg[u].r, seg[v].r, mid + 1, e, k - missing_left);
}


int st[N], fi[N];
int timer = 0;
int ara[N];
// dfs for euler tour
// calculate entering time end leaving time of each node...
void dfs(int u, int p){
    st[u] = ++timer;
    ara[timer] = a[u];
    for(auto v : g[u]){
        if(v != p) dfs(v, u);
    }
    fi[u] = timer;
}
 
 
void solve(){
 
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
 
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer = 0;
    dfs(1, 0);
    for(int i=1;i<=n;i++) cout << st[i] << " " << fi[i] << endl;
    // for(int i=1;i<=n;i++) cout << ara[i] << " "; cout << endl;
    // build persistent segtree on euler array
    idx = 0;
    root[0] = 0;
    for(int i=1;i<=timer;i++){
        root[i] = update(root[i-1], 1, MAXV, ara[i]);
    }

    while(q--){
        int p, k; cin >> p >> k;
        int l = st[p], r = fi[p];
        cout << l << " " << r << endl;
        int ans = kth_missing(root[l-1], root[r], 1, MAXV, k);
        cout << ans << "\n";
    }
    
}

void reset(){
    for(int i=1;i<=n;i++){
        g[i].clear();
        st[i] = fi[i] = 0;
    }
    timer = 0;
    idx = 0;
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