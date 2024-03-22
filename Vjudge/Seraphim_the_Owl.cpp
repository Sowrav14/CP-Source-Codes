#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,m; cin >> n >> m;
    vector<int>a(n+1), b(n+1), p(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        cin >> b[i];
        p[i] = p[i-1] + b[i];
    }

    int ans = INT_MAX;
    for(int i=m;i>=1;i--){
        int cur = a[i];
        int rem = p[m]- p[i];
        int tot = cur + rem;
        ans = min(ans, tot);
    }
    // cout << ans << endl;
    for(int i=m+1;i<=n;i++){
        ans += min(a[i], b[i]);
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}