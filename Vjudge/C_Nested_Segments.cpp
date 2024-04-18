#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
int freq[N], ans[N];
int tree[4*N];

void update(int node, int l, int r, int i, int val){
    if(l>i or r<i) return;
    if(l == r) {
        tree[node] = val;
        return;
    }

    int m = (l + r) / 2;
    update(2*node, l, m, i, val);
    update(2*node+1, m+1, r, i, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int l, int r, int i, int j){
    if(l>j or r<i) return 0;
    if(l>=i and r<=j) return tree[node];
    
    int m = (l + r) / 2;
    int left = query(2*node, l, m, i, j);
    int right = query(2*node+1, m+1, r, i, j);
    return left + right;
}



void solve(){

    int n; cin >> n;
    for(int i=1;i<=2*n;i++){
        int x; cin >> x;
        if(freq[x] == 0){
            freq[x] = i;
        } else{
            int l = freq[x];
            int r = i;
            int res = query(1, 1, 2*n, l, r);
            ans[x] = res;
            update(1, 1, 2*n, l, 1);
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    } cout << endl;

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