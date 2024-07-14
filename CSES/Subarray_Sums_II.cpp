#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,k; cin >> n >> k;
    vector<int>v(n+1, 0), a(n+1, 0);
    map<int, vector<int>>m;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        a[i] = a[i-1] + v[i];
        m[a[i]].push_back(i);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int cur = a[i];
        int need = cur + k;
        if(m[need].size() == 0) continue;
        int it = upper_bound(m[need].begin(), m[need].end(), i) - m[need].begin();
        ans += (m[need].size() - it);
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