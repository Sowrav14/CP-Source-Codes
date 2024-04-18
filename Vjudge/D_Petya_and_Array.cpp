#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
int a[N];
vector<int> tree[4*N];

void merge(vector<int> &ret, vector<int>&x, vector<int>&y){
    int i=0, j=0;
    while(i < x.size() and j < y.size()){
        if(x[i] < y[j]){
            ret.push_back(x[i++]);
        } else{
            ret.push_back(y[j++]);
        }
    }
    while(i < x.size()){
        ret.push_back(x[i++]);
    }
    while(j < y.size()){
        ret.push_back(y[j++]);
    }
}

void build(int node, int l, int r){
    if(l == r){
        tree[node].push_back(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    merge(tree[node], tree[2*node], tree[2*node+1]);
}

int query(int node, int l, int r, int i, int j, int k){
    
    if(l>j or r<i){
        return 0;
    }
    if(l>=i and r<=j){
        int x = lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        return x;
    }
    int m = (l + r) / 2;
    int left = query(2*node, l, m, i, j, k);
    int right = query(2*node+1, m+1, r, i, j, k);
    return left + right;
}

void solve(){

    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    build(1, 1, n);
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = a[i-1] + k;
        int ret = query(1, 1, n, i, n, x);
        ans += ret;
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