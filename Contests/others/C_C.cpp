#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int a[N];
int tree[4*N], prop[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = min(tree[2*node], tree[2*node + 1]);

}

void singleupdate(int node, int l, int r, int i, int val){

    if(l>i or r<i) return;
    if(l == r){
        tree[node] = val;
        return;
    }

    int mid = (l + r) / 2;
    singleupdate(2*node, l, mid, i, val);
    singleupdate(2*node+1, mid+1, r, i, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}



int query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return inf;
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j);
    int right = query(2*node+1, mid+1, r, i, j);
    return min(left, right);
}

void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n+1;i<=2*n;i++) a[i] = a[i-n];
    for(int i=2;i<=2*n;i++) a[i] += a[i-1];
    build(1, 1, 2*n);

    int ans = 0;
    for(int l=1;l<=n;l++){
        int r = l + n - 1;
        int x = a[l - 1];

        int y = query(1, 1, 2*n, l, r);
        if(y >= x) ans++;
    }
    cout << ans << endl;

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