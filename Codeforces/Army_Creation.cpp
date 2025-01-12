#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, k;
int a[N];
int pre[N];
vector<int> indices[N];

struct PST {
    #define lc t[cur].l
    #define rc t[cur].r
    struct node {
        int l = 0, r = 0, val = 0;
    } t[40 * N];
    int root[N];
    int T = 0;
    int build(int b, int e) {
        int cur = ++T;
        if (b == e){
            t[cur].val = 0;
            return cur;
        }
        int mid = b + e >> 1;
        lc = build(b, mid);
        rc = build(mid + 1, e);
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }
    int p_update(int pre, int b, int e, int i, int v){
        int cur = ++T;
        t[cur] = t[pre];
        if (b == e){
            t[cur].val += v;
            return cur;
        }
        int mid = b + e >> 1;
        if (i <= mid){
            rc = t[pre].r;
            lc = p_update(t[pre].l, b, mid, i, v);
        } else {
            lc = t[pre].l;
            rc = p_update(t[pre].r, mid + 1, e, i, v);
        }
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }
    int query_sum(int cur, int b, int e, int i, int j){
        if(e < i or b > j) return 0;
        if(b>=i and e<=j) return t[cur].val;

        int m = (b + e) / 2;
        int left = query_sum(t[cur].l, b, m, i, j);
        int right = query_sum(t[cur].r, m+1, e, i, j);
        return left + right;
    }
    void setTree(int cur,int b, int e){
        if(b == e){
            cout << " [ " << b << ", " << e << " ] -- " << t[cur].val << endl;
            return;
        }
        int m = (b + e) / 2;
        setTree(t[cur].l, b, m);
        setTree(t[cur].r, m+1, e);
        return;
    }
} pst;

void solve(){

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        pre[i] = 0;
        int sz = indices[a[i]].size();
        // if no more that k element of same type before it 
            //assume it a distinct element.
        // else
            // keep track of prev kth element.
        if(sz >= k){
            pre[i] = indices[a[i]][sz-k];
        }
        indices[a[i]].push_back(i);
    }
    // for(int i=1;i<=n;i++) cout << pre[i] << " \n"[i == n];
    pst.root[0] = pst.build(1, n);
    // build the pst to query with rth root.
    for(int i=1;i<=n;i++){
        pst.root[i] = pst.p_update(pst.root[i-1], 1, n, i, 1);
        // if more than k element before it.
        // reset prev kth element to avoid overcount.
        if(pre[i] != 0){
            pst.root[i] = pst.p_update(pst.root[i], 1, n, pre[i], -1);
        }
    }

    int q; cin >> q;
    int last = 0;
    while(q--){
        int x, y; cin >> x >> y;
        int l = ((x + last) % n) + 1;
        int r = ((y + last) % n) + 1;
        if(l > r) swap(l, r);
        last = pst.query_sum(pst.root[r], 1, n, l, r);
        cout << last << endl;
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