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
        int nl = (l == s ? l + b.l : l);
        int nr = (b.r == b.s ? b.r + r : b.r);
        int ns = s + b.s;

        return Node(ng, nl, nr, ns);
    }
} One(1, 1, 1, 1), Zero(0, 0, 0, 1);

int a[N];
Node t0[4*N], t1[4*N];

void update0(int n, int l, int r, int i, Node v){
    if(r < i or l > i) return;
    if(l == r){
        t0[n] = v;
        return;
    }
    int m = (l + r) / 2;
    update0(2*n, l, m, i, v);
    update0(2*n+1, m+1, r, i, v);
    t0[n] = t0[2*n] + t0[2*n+1];
    return;
}

void update1(int n, int l, int r, int i, Node v){
    if(r < i or l > i) return;
    if(l == r){
        t1[n] = v;
        return;
    }
    int m = (l + r) / 2;
    update1(2*n, l, m, i, v);
    update1(2*n+1, m+1, r, i, v);
    t1[n] = t1[2*n] + t1[2*n+1];
    return;
}


void solve(){

    string s; cin >> s;
    int n; n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            update0(1, 1, n, i+1, One);
            update1(1, 1, n, i+1, Zero);
        } else {
            update1(1, 1, n, i+1, One);
            update0(1, 1, n, i+1, Zero);
        }
    }
    
    int q; cin >> q;
    while (q--){
        int i; cin >> i; i--;
        if(s[i] == '1'){
            update0(1, 1, n, i+1, One);
            update1(1, 1, n, i+1, Zero);
            s[i] = '0';
        } else {
            update1(1, 1, n, i+1, One);
            update0(1, 1, n, i+1, Zero);
            s[i] = '1';
        }

        cout << max(t0[1].g, t1[1].g) << " ";
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