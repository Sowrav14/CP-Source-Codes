#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,m; cin >> n >> m;
    vector<int>a(7, 0);

    for(int i=0;i<n;i++){
        char c; cin >> c;
        a[c-'A']++;
    }

    int ans = 0;

    for(int i=0;i<7;i++){
        // cout << a[i] << " ";
        ans += max(m - a[i], 0ll);
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