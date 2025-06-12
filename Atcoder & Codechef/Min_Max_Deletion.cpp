#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, q; cin >> n >> q;
    vector<int> a(n+2, 0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ans += min(a[i], a[i-1]);
    }
    while(q--){
        int i, x; cin >> i >> x;
        ans -= min(a[i-1], a[i]);
        ans -= min(a[i+1], a[i]);
        ans += min(a[i-1], x);
        ans += min(a[i+1], x);
        a[i] = x;
        cout << ans << endl;
    }

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