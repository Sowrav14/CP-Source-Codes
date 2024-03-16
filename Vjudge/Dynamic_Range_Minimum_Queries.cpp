#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 2e5+10;
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
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int node, int l, int r, int i, int j){
    if(l>j or r<i) return INT_MAX;
    if(l>=i and r<=j) return tree[node];
    int m = (l + r) / 2;
    return min(query(2*node, l, m, i, j), query(2*node+1, m+1, r, i, j));
}

void update(int node, int l, int r, int i, int x){
    if(l > i or r < i) return;
    if(l == r) {
        tree[node] = x;
        return;
    }

    int m = (l + r) / 2;
    update(2*node, l, m, i, x);
    update(2*node+1, m+1, r, i, x);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void solve(){

    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            update(1, 1, n, l, r);
        } else {
            cout << query(1, 1, n, l, r) << endl;
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