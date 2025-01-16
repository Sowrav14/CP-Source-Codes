#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 35000 + 10;
const int K = 110;
const int M = 1e9 + 7;
const int inf = 1e15;

int n, k;
int a[N];

/*      L to R sum of position of all distinct values       */
 
struct PST {
    #define lc t[cur].l
    #define rc t[cur].r
    struct node {
        int l = 0, r = 0, val = 0;
    } t[60 * N];
    int proot[N], nroot[N];
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
    void seTree(int cur,int b, int e){
        if(b == e){
            cout << " [ " << b << ", " << e << " ] -- " << t[cur].val << endl;
            return;
        }
        int m = (b + e) / 2;
        seTree(t[cur].l, b, m);
        seTree(t[cur].r, m+1, e);
        return;
    }
} pst;

int pre[N];
void pst_config(){
    // for last occurence...
    pst.proot[0] = pst.build(1, n);
    for(int i=1;i<=n;i++){
        pst.proot[i] = pst.p_update(pst.proot[i-1], 1, n, i, i);
        if(pre[a[i]] != 0){
            pst.proot[i] = pst.p_update(pst.proot[i], 1, n, pre[a[i]], -pre[a[i]]);
        }
        pre[a[i]] = i;
    }
    for(int i=0;i<=n;i++) pre[i] = 0;
    // for first occurence...
    pst.nroot[n+1] = pst.build(1, n);
    for(int i=n;i>=1;i--){
        pst.nroot[i] = pst.p_update(pst.nroot[i+1], 1, n, i, i);
        if(pre[a[i]] != 0){
            pst.nroot[i] = pst.p_update(pst.nroot[i], 1, n, pre[a[i]], -pre[a[i]]);
        }
        pre[a[i]] = i;
    }
}
// return the difference of first occurence and last occurence of 
// distinct elements present in l to r...
int cost(int l, int r){
    int pos = pst.query_sum(pst.proot[r], 1, n, l, r);
    int neg = pst.query_sum(pst.nroot[l], 1, n, l, r);
    return pos - neg;
}

/*      Divide and Conquer DP Parts     */
int dp[K][N];
void dndp(int i, int l, int r, int optl, int optr){
    if(l > r) return;
    int m = (l + r) / 2;
    pair<int,int> best = {inf, l};
    for(int j=optl;j<min(m, optr+1);j++){
        best = min(best, {(dp[i-1][j] + cost(j+1, m)), j});
    }
    int opt = best.second;
    dp[i][m] = best.first;
    dndp(i, l, m - 1, optl, opt);
    dndp(i, m + 1, r, opt, optr);
}

void solve(){

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    pst_config();
    
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = inf;
        }
    }
    for(int i=1;i<=n;i++){
        dp[1][i] = cost(1, i);
    }
    for(int i=2;i<=k;i++) dndp(i, 1, n, 0, n-1);
    cout << dp[k][n] << endl;

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