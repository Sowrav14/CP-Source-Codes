#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int a[N];
int tree[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = max(tree[2*node], tree[2*node + 1]);

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
    tree[node] = max(tree[2*node], tree[2*node+1]);
}





int query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return 0;
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j);
    int right = query(2*node+1, mid+1, r, i, j);
    return max(left, right);
}

void solve(){

    int n, q; cin >> n >> q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    if(n == 1){
        while(q--){
            int t, i, h; cin >> t >> i >> h;
            if(t == 1){
                v[i] = h;
            } else {
                cout << 1 << endl;
            }
        }
        return;
    }
    
    for(int i=1;i<n;i++) a[i] = abs(v[i+1] - v[i]);

    build(1, 1, n-1);

    // cout << query(1, 1, n-1, 1, 4) << endl;
    while(q--){
        int t, i, h; cin >> t >> i >> h;
        if(t == 1){
            v[i] = h;
            a[i-1] = abs(v[i] - v[i-1]);
            a[i] = abs(v[i+1] - v[i]);
            singleupdate(1, 1, n-1, i, a[i]);
            singleupdate(1, 1, n-1, i-1, a[i-1]);
        } else {
            // for(int i=1;i<n;i++) cout << a[i] << " "; cout << endl;
            int L = i, R = i;
            int l = i, r = n - 1;
            while(l <= r){
                int m = (l + r) / 2;
                if(query(1, 1, n-1, i, m) <= h){
                    L = m + 1;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            l = 1, r = i-1;
            while(l <= r){
                int m = (l + r) / 2;
                if(query(1, 1, n-1, m, i) <= h){
                    r = m - 1;
                    R = m;
                } else {
                    l = m + 1;
                }
            }
            // cout << L << " - " << R << " - ";
            cout << L - R + 1 << endl;
        }
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