#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n), c(n);
    for(int i=0;i<n;i++){
        a[i] = s[i] - '0';
        int want = (i%2 == 0 ? 0 : 1);
        c[i] = a[i] ^ want;
    }

    auto attempt = [&] (int g) -> int {
        vector<int> x(n, 0);
        x[0] = g;
        if(n >= 2) x[1] = c[0] ^ x[0];
        for(int i=1;i<=n-2;i++){
            x[i+1] = x[i-1] ^ x[i] ^ c[i];
        }
        bool ok = true;
        if(n == 1){
            if(x[0] != c[0]) ok = false;
        } else {
            if( (x[n-2] ^ x[n-1]) != c[n-1] ) ok = false;
        }
        if(!ok) return inf;
        int cnt = 0;
        for(int i=0;i<n;i++) cnt += x[i];
        return cnt;
    };
    
    int ans = min(attempt(0), attempt(1));
    if(ans >= inf) cout << -1 << endl;
    else cout << ans << endl;
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
