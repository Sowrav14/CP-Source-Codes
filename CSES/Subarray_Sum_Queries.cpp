#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Node {
    int g, l, r, s;
    Node(){}
    Node(int g, int l, int r, int s) : g(g), l(l), r(r), s(s) {}

    Node operator+ (Node b){
        int ng = max({g, b.g, r + b.l});
        int nl = max({l, s + b.l});
        int nr = max({r + b.s, b.r});
        int ns = s + b.s;

        return Node(ng, nl, nr, ns);
    }
};

int a[N];
Node t[4*N];

void build(int n, int l, int r){
    if(l == r){
        t[n] = Node(max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2*n, l, m);
    build(2*n+1, m+1, r);
    t[n] = t[2*n] + t[2*n+1];
    return;
}

void update(int n, int l, int r, int i, int v){
    if(r < i or l > i) return;
    if(l == r){
        t[n] = {max(0ll, v), max(0ll, v), max(0ll, v), v};
        return;
    }
    int m = (l + r) / 2;
    update(2*n, l, m, i, v);
    update(2*n+1, m+1, r, i, v);
    t[n] = t[2*n] + t[2*n+1];
    return;
}

// return maximum subarray sum node from [i...j];
Node query(int n, int l, int r, int i, int j){
    if(r<i or l>j) return Node(0, 0, 0, 0);
    if(l>=i and r<=j) return t[n];

    int m = (l + r) / 2;
    Node left = query(2*n, l, m, i, j);
    Node right = query(2*n+1, m+1, r, i, j);
    return left + right;
}


void solve(){

    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int i, v; cin >> i >> v;
        update(1, 1, n, i, v);
        cout << t[1].g << endl;
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