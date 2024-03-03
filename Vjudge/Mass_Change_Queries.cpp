#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    // for(int i=0;i<n;i++) cout << v[i] << " "; cout << endl;
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int l,r,x,y; cin >> l >> r >> x >> y;
        for(int j=l;j<=r;j++){
            if(v[j] == x) v[j] = y;
        }
    }
    for(int i=1;i<=n;i++) cout << v[i] << " ";  cout << endl;

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