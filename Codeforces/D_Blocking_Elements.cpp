#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e16;
const int N = 2e5+10;
int tree[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] =0;
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
    vector<int>v(n+2, 0), pref(n+2, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    } pref[n+1] = pref[n];
    int ans = inf;
    int l=0, r=pref[n];
    while(l <= r){
        int m = (l + r) / 2;
        
        vector<int>next(n+1);
        build(1, 1, n+1);
        for(int i=0;i<=n;i++){
            int it = upper_bound(pref.begin(), pref.end(), m+pref[i]) - pref.begin();
            it = min(it, n+1);
            next[i] = it;
        }
        // cout << m << endl;
        // for(int i=0;i<=n;i++) cout << next[i] << " "; cout << endl;
        for(int i=n;i>=1;i--){
            int mn = query(1, 1, n+1, i+1, next[i]);
            singleupdate(1, 1, n+1, i, mn+v[i]);
        }
        int res = query(1, 1, n+1, 1, next[0]);

        if(res <= m){
            ans = m;
            r = m - 1;
        } else{
            l = m + 1;
        }
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}