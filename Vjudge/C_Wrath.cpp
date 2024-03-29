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

    vector<int>left(n+1, 0), right(n+1, 0);
    for(int i=n;i>1;i--){
        int x = v[i];
        if(x == 0) continue;
        int l = max(1ll, i-x);
        int r = i-1;
        // cout << l << " " << r << endl;
        left[l] += 1;
        right[r] += 1;
    }

    int ans = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += left[i];
        if(cnt == 0) ans++;
        cnt -= right[i];
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