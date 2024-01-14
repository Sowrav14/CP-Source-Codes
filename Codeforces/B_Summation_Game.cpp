#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    int a,b; cin >> a >> b;
    vector<int>v(n+1, 0), pref(n+10);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + v[i];
        // cout << pref[i] << " ";
    } 
    int ans = INT_MIN;
    for(int i=n;i>=n-a;i--){
        int bob = i - b;
        if(bob < 0) bob = 0;
        int sum = pref[bob];
        int red = pref[i] - pref[bob];
        int res = sum - red;
        ans = max(ans, res);
    }
    cout << ans << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}