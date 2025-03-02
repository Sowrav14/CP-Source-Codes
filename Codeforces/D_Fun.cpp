#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, x; cin >> n >> x;
    int ans = 0;
    for (int a = 1; a <= min(n, x); a++){
        for (int b = 1; a * b <= n and a + b <= x; b++){
            int c = min((n - a * b) / (a + b), x - (a + b));
            ans += c;
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