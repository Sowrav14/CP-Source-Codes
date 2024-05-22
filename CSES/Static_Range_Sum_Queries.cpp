#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
void solve(){
 
    int n,q; cin >> n >> q;
    vector<int>v(n+1, 0);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        v[i] = v[i-1] + x;
    }
    while(q--){
        int l,r; cin >> l >> r;
        cout << v[r] - v[l-1] << endl;
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