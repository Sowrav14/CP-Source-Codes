#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 30000 + 10;
const int MAX = 1e6+10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int a[N], pre[N];
int oc[MAX];
vector<int> tree[4*N];

void merge(vector<int>&x, vector<int>&a, vector<int>&b){
    int i = 0, j = 0;
    while(i<a.size() and j<b.size()){
        if(a[i] < b[j]){
            x.push_back(a[i]);
            i++;
        } else {
            x.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()){
        x.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        x.push_back(b[j]);
        j++;
    }
}

void build(int n, int b, int e){
    if(b == e){
        tree[n].push_back(pre[b]);
        return;
    }
    int m = (b + e) / 2;
    build(2*n, b, m);
    build(2*n+1, m+1, e);
    merge(tree[n], tree[2*n], tree[2*n+1]);
}

// return numbers of element in [l...r] that are strictly less than k
int query(int n, int b, int e, int l, int r, int k){
    if(b>r or e<l) return 0;
    if(b>=l and e<=r){
        int x = lower_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
        return x;
    }
    int m = (b + e) / 2;
    int left = query(2*n, b, m, l, r, k);
    int right = query(2*n+1, m+1, e, l, r, k);
    return left + right;
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = oc[a[i]];
        oc[a[i]] = i;
    }
    // for(int i=1;i<=n;i++) cout << pre[i] << " \n"[i == n];

    build(1, 1, n);
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r, l) << endl;
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