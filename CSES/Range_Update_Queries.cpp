#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
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
    tree[node] = tree[2*node] + tree[2*node + 1];

}


void rangeupdate(int node, int l, int r, int i, int j, int val){
    if(i>r or j<l) return;
    if(i<=l and j>=r){
        tree[node] += (r - l + 1) * val;
	    prop[node] += val;
        return;
    }


    int mid = (l + r) / 2;
    rangeupdate(2*node, l, mid, i, j, val);
    rangeupdate(2*node+1, mid+1, r, i, j, val);
    tree[node] = tree[2*node] + tree[2*node+1] + (r - l + 1) * prop[node];
}


int query(int node, int l, int r, int i, int j, int val = 0){
    if(i>r or j<l){
        return 0;
    }
    if(i<=l and j>=r){
        return tree[node] + (r - l + 1) * val;
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j, val+prop[node]);
    int right = query(2*node+1, mid+1, r, i, j, val+prop[node]);
    return left + right;
}



void solve(){

    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);

    while(q--){
        int t; cin >> t;
        if(t == 2){
            int id; cin >> id;
            cout << query(1, 1, n, id, id) << endl;
        } else{
            int a,b,val; cin >> a >> b >> val;
            rangeupdate(1, 1, n, a, b, val);
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