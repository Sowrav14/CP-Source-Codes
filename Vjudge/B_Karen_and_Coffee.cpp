#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 2e5+10;
int a[N];
int larr[N], rarr[N];

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
        // cout << l << " " << r << " " << tree[node].back() << endl;
        if(tree[node].back() < k) return 0;
        int x = lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        return tree[node].size() - x;
    }
    int m = (l + r) / 2;
    int left = query(2*node, l, m, i, j, k);
    int right = query(2*node+1, m+1, r, i, j, k);
    return left + right;
}


void solve(){

    int n,k,q; cin >> n >> k >> q;
    larr[0] = 0;
    for(int i=0;i<n;i++){
        int l,r; cin >> l >> r;
        larr[l] += 1;
        rarr[r] += 1;
    }

    int cnt = 0;
    for(int i=1;i<N-9;i++){
        cnt += larr[i];
        a[i] = cnt;
        cnt -= rarr[i];
    }

    // for(int i=90;i<=100;i++) cout << a[i] << " "; cout << endl;

    build(1, 1, N-9);

    for(int i=0;i<q;i++){
        int l,r; cin >> l >> r;
        cout << query(1, 1, N-9, l, r, k) << endl;
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