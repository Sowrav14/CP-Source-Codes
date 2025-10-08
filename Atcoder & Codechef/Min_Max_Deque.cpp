#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4*n);
        build(a, 1, 1, n);
    }

    void build(const vector<int>& a, int node, int l, int r){
        if(l == r){ 
            tree[node] = a[l-1];
            return;
        }
        int m = (l + r) / 2;
        build(a, 2*node, l, m);
        build(a, 2*node+1, m + 1, r);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int x){ 
        return query(1, 1, n, x); 
    }

    int query(int node, int l, int r, int x){
        if(tree[node] < x) return 0;
        if(l == r) return l;
        int m = (l + r) / 2;
        int find = query(2*node+1, m + 1, r, x);
        if(find) return find;
        return query(2*node, l, m, x);
    }

    void update(int idx, int val){ 
        update(1, 1, n, idx, val);
    }

    void update(int node, int tl, int tr, int idx, int val){
        if(tl == tr){
            tree[node] = val; return; 
        }
        int m = (tl + tr) / 2;
        if(idx <= m) update(2*node, tl, m, idx, val);
        else update(2*node+1, m + 1, tr, idx, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
};


void solve(){

    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> alice, bob;
    for(int i=0;i<n;i++){
        if(i%2){
            alice.push_back(v[i]);
            bob.push_back(-1000000);
        } else {
            alice.push_back(-1);
            bob.push_back(-v[i]);
        }
    }
    SegmentTree sta(alice), stb(bob);

    auto check = [&] (int m) -> bool {
        if(v[n-1] < m) return 0;
        int one = sta.query(m);
        int zero = stb.query(-m + 1);

        if(one == 0 and zero == 0) return 1;
        return one > zero;
    };

    auto bs = [&] () -> int {
        int l = 1, r = 200010;
        int ans = 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(check(m)){
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    };

    cout << bs() << " ";
    while(q--){
        int i, x; cin >> i >> x;
        v[i-1] = x;
        if(i%2){
            stb.update(i, -x);
        } else {
            sta.update(i, x);
        }
        cout << bs() << " ";
    }
    cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}