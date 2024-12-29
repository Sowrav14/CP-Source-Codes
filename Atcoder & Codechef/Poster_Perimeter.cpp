#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b, k; cin >> a >> b >> k;
    int ans = INT_MAX;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            int p = 2 * (i + j);
            int diff = abs(k - p);

            ans = min(ans, diff);
        }
    }
    cout << ans << endl;

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