#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    int a[3] = {0};
    for(int i=0;i<n;i++){
        int x; cin >> x;
        a[x%3]++;
    }

    int ans = 0;
    ans += a[0] / 2;
    ans += min(a[1], a[2]);

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