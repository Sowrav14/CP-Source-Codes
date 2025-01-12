#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 35000 + 10;
const int K = 55;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, k;
int a[N];
int dp[K][N];

/*                    PST for Distinct Element Queries                */
int pre[N];
int oc[N];
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
} pst;
void pst_config(){
    for(int i=1;i<=n;i++){
        pre[i] = oc[a[i]];
        oc[a[i]] = i;
    }
    for(int i=1;i<=n;i++){
        indices[pre[i]].push_back(i);
    }
    pst.root[0] = pst.build(1, n);
    for(int i=0;i<=n;i++){
        if(i != 0) pst.root[i] = pst.root[i-1];
        for(auto id : indices[i]){
            pst.root[i] = pst.p_update(pst.root[i], 1, n, id, 1);
        }
    }
}
int cost(int i, int j){
    return pst.query_sum(pst.root[i-1], 1, n, i, j);
}
/*              Divide and Conquer DP                   */
void dc_dp(int i, int l, int r, int optl, int optr){
    if(l > r) return;

    int m = (l + r) / 2;
    pair<int,int>best = {0, l};
    for(int j=optl;j<min(optr+1, m);j++){
        best = max(best, {dp[i-1][j] + cost(j+1, m), j});
    }
    dp[i][m] = best.first;
    int opt = best.second;

    dc_dp(i, l, m-1, optl, opt);
    dc_dp(i, m+1, r, opt, optr);
}

void solve(){

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    pst_config();
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    // dp[0][0] = 0;
    for(int i=1;i<=n;i++) dp[1][i] = cost(1, i);
    for(int i=2;i<=k;i++) dc_dp(i, 1, n, 0, n-1);

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