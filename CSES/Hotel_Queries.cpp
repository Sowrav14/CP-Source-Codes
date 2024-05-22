#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
 
int a[N];
int t[4*N];
 
void build(int n, int l, int r){
    if(l == r) {
        t[n] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2*n, l, m);
    build(2*n+1, m+1, r);
    t[n] = max(t[2*n], t[2*n+1]);
}
 
void update(int n, int l, int r, int i, int v){
    if(i < l or i > r) return;
    if(l == r){
        t[n] -= v;
        return;
    }
 
    int m = (l + r) / 2;
    update(2*n, l, m, i, v);
    update(2*n+1, m+1, r, i, v);
    t[n] = max(t[2*n], t[2*n+1]);
}
 
 
int query(int n, int l, int r, int v){
    if(t[n] < v) return 0;
    if(l == r) return l;
    int m = (l + r) / 2;
    if(t[2*n] >= v){
        return query(2*n, l, m, v);
    } else{
        return query(2*n+1, m+1, r, v);
    }
}
 
void ptree(){
    for(int i=1;i<=2*8;i++){
        cout << t[i] << " ";
    } cout << endl;
}
 
 
void solve(){
 
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    for(int i=1;i<=m;i++){
        int x; cin >> x;
        int id = query(1, 1, n, x);
        update(1, 1, n, id, x);
        // ptree();
        cout << id << " ";
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
