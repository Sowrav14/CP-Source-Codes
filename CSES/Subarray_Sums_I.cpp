#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
void solve(){
 
    int n,k; cin >> n >> k;
    vector<int>v(n+1, 0), pref(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }
 
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = pref[i];
        int req = k + pref[i-1];
        int it = lower_bound(pref.begin(), pref.end(), req) - pref.begin();
        if(it != n+1 and pref[it] == req) ans++;
        // cout << i << " " << req << " " << it << " " << ans << endl;
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
