#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
 
struct PST {
    #define lc t[cur].l
    #define rc t[cur].r
 
    // defining node for segment tree...
    struct node {
        int l = 0, r = 0, val = 0;
    } t[20 * N];
 
    // build the initial tree...
    int T = 0;
    int build(int b, int e) {
        int cur = ++T;
        if (b == e){
            return cur;
        }
        int mid = b + e >> 1;
        lc = build(b, mid);
        rc = build(mid + 1, e);
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }
 
    // single point update
    int upd(int pre, int b, int e, int i, int v){
        int cur = ++T;
        t[cur] = t[pre];
        if (b == e){
            t[cur].val += v;
            return cur;
        }
 
        int mid = b + e >> 1;
        if (i <= mid){
            rc = t[pre].r;
            lc = upd(t[pre].l, b, mid, i, v);
        } else {
            lc = t[pre].l;
            rc = upd(t[pre].r, mid + 1, e, i, v);
        }
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }
    int query(int pre, int cur, int b, int e, int k){
        if (b == e){
            return b;
        }
        int cnt = t[lc].val - t[t[pre].l].val;
        int mid = b + e >> 1;
        if (cnt >= k)
            return query(t[pre].l, lc, b, mid, k);
        else
            return query(t[pre].r, rc, mid + 1, e, k - cnt);
    }
} t;
 
 
 
int V[N], root[N], a[N];
 
void solve(){
 
    map<int, int>mp;
    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i], mp[a[i]];
    
    // mapping element with conitigous values.
    int c = 0;
    for(auto x : mp) mp[x.first] = ++c, V[c] = x.first;
 
    // Updating elements one by one.
    // new branch is creating every time so root will change.
    root[0] = t.build(1, n);
    for(int i = 1; i <= n; i++) {
        root[i] = t.upd(root[i - 1], 1, n, mp[a[i]], 1);
        // cout << root[i] << endl;
    }
 
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        // trace which node update at kth
        // when the segment tree make transition from l-1 th version to r th 
        cout << V[t.query(root[l - 1], root[r], 1, n, k)] << '\n';
    }
 
}
 
signed main() {
    Fast_IO() 
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
} 