#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n+2), pref(n+2, 0), ans(n+2, 0);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a[x]++;
    }

    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + a[i];

    int prev = 0;
    for(int i=0;i<=n;i++){
        int mn = a[i];
        int mx = a[i] + prev + pref[n] - pref[i];
        // cout << i << " " << a[i] << " " << mn << " " << mx << endl;
        ans[mn]++;
        ans[mx+1]--;
        if(a[i] == 0) break;
        prev += a[i] - 1;
    }
    // for(int i=0;i<=n+1;i++) cout << ans[i] << " \n"[i == n+1];
    for(int i=1;i<=n;i++){
        ans[i] += ans[i-1];
    }
    for(int i=0;i<=n;i++) cout << ans[i] << " \n"[i == n];

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