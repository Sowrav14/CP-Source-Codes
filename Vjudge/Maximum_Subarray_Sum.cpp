#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
const int inf = -1e15;
int a[N];
int tree[4*N];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int query(int node, int l, int r, int i, int j){
    if(l>j or r<i) return inf;
    if(l >= i and r <= j){
        return tree[node];
    }
    int m = (l + r) / 2;
    int left = query(2*node, l, m, i, j);
    int right = query(2*node+1, m+1, r, i, j);
    return max(left, right);
}


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        a[i] = a[i-1] + v[i-1];
    }

    // for(int i=1;i<=n;i++) cout << a[i] << " "; cout << endl;

    build(1, 1, n);
    int ans = inf;
    for(int i=1;i<=n;i++){
        int cur = a[i-1];
        int mx = query(1, 1, n, i, n);
        ans = max(mx - cur, ans);
    }
    cout << ans << endl;

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