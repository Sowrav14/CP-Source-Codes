#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int g = 0;

    for(int i=1;i<n;i++){
        int curdis = v[i] - v[i-1];
        g = __gcd(g, curdis);
    }

    int ans = 0;
    for(int i=1;i<n;i++){
        int curdis = v[i] - v[i-1];
        ans += (curdis / g) - 1;
    }
    

    cout << ans << endl;

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