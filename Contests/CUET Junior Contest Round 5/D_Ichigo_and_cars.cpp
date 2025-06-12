#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    ans += (a / 2);
    a %= 2;
    ans += (b / 4) * 3ll;
    b %= 4;
    ans += c;
    ans += b;
    if(b < 2) ans += a;

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