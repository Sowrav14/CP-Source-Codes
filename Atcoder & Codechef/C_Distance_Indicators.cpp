#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n+1);
    int mx = 0;
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    map<int,int> m;
    for(int i=1;i<=n;i++){
        int x = i - v[i];
        if(x <= 0) continue;
        m[x]++;
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = i + v[i];
        int y = i - v[i];
        int cnt = m[x];
        // cout << cnt << endl;
        if(x == y) cnt--;
        ans += cnt;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}