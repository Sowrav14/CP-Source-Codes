#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e18;


void solve(){
    int n, w; 
    cin >> n >> w;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    if(w > n){
        cout << 0 << endl;
        return;
    }

    int m = 2 * w;
    vector<int> md(m, 0);

    for(int i=1;i<=n;i++){
        md[(i-1)%m] += a[i];
    }

    vector<int> pref(2*m + 1, 0);
    for(int i=0;i<2*m;i++){
        pref[i+1] = pref[i] + md[i % m];
    }

    int ans = inf;
    for(int i=0;i<m;i++){
        ans = min(ans, pref[i+w] - pref[i]);
    }

    cout << ans << endl;
}

signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
