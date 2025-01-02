#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// works in O(n * b)
double dp[N];
double recur(int x, int a, int b, int l){
    if(x <= 0) return 0.0;
    if(dp[x] != -1.0) return dp[x];
    double ans = 1.0;
    for(int i=a;i<=b;i++){
        ans += (1.0 / l) * recur(x-i, a, b, l);
    }
    return dp[x] = ans;
}

double ev[N];
double tree[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = 0.0;
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
        tree[node] = val;
        return;
    }

    int mid = (l + r) / 2;
    singleupdate(2*node, l, mid, i, val);
    singleupdate(2*node+1, mid+1, r, i, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

double query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return 0.0;
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    double left = query(2*node, l, mid, i, j);
    double right = query(2*node+1, mid+1, r, i, j);
    return left + right;
}

void solve(){

    int n, a, b; cin >> n >> a >> b;
    int L = b - a + 1;
    build(1, 0, n);
    for(int i=1;i<=n;i++){
        int r = max(0ll, min(i-1, i-a));
        int l = max(0ll, i - b);

        double prev = query(1, 0, n, l, r);
        ev[i] = 1.0 * L + prev;
        if(a == 0){
            ev[i] /= (L - 1.0);
        } else {
            ev[i] /= (L * 1.0);
        }
        singleupdate(1, 0, n, i, ev[i]);
    }
    cout << fixed << setprecision(10) << ev[n] << endl;

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