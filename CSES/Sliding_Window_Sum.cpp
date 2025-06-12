#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    int ans = x, l = x;
    for(int i=1;i<k;i++){
        x = (a * x + b) % c;
        ans += x;
    }
    int res = ans;
    for(int i=k;i<n;i++){
        x = (a * x + b) % c;
        res += x;
        res -= l;
        ans ^= res;
        l = (a * l + b) % c;
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