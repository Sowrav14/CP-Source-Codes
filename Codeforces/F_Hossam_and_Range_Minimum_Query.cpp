#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
 
struct PST {
    #define lc t[cur].l
    #define rc t[cur].r
 
    // defining node for segment tree...
    struct node {
        int l = 0, r = 0, val = 0;
    } t[40 * N];
 
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
        t[cur].val = t[lc].val ^ t[rc].val;
        return cur;
    }
 
    // single point update
    int upd(int pre, int b, int e, int i, int v){
        int cur = ++T;
        t[cur] = t[pre];
        if (b == e){
            t[cur].val ^= v;
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
        t[cur].val = t[lc].val ^ t[rc].val;
        return cur;
    }
    int query(int pre, int cur, int b, int e){
        if (b == e){
            if(t[pre].val == t[cur].val) return 0;
            return b;
        }
        int cnt = t[lc].val ^ t[t[pre].l].val;
        int mid = b + e >> 1;
        if (cnt != 0)
            return query(t[pre].l, lc, b, mid);
        else
            return query(t[pre].r, rc, mid + 1, e);
    }
} t;
 
 
 
int id[N], rid[N], root[N], a[N];
 
void solve(){
 
    map<int, int>mp;
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i], mp[a[i]];
    
    // mapping element with conitigous values.
    int c = 0;
    for(auto x : mp){
        mp[x.first] = ++c;
        rid[c] = x.first;
    }
 
    // Updating elements one by one.
    // new branch is creating every time so root will change.
    root[0] = t.build(1, n);
    for(int i = 1; i <= n; i++) {
        root[i] = t.upd(root[i - 1], 1, n, mp[a[i]], a[i]*1234567);
    }
    
    int last = 0;
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        int l, r;
        l = max(1ll, last ^ x);
        r = min(n, last ^ y);
        if(l > r){
            cout << 0 << endl;
            continue;
        }
        last =  rid[t.query(root[l - 1], root[r], 1, n)];
        cout << last << '\n';
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