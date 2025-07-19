#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b, x, y; cin >> a >> b >> x >> y;
    if(a - 1 > b){
        cout << -1 << endl;
        return;
    }

    if(a-1 == b){
        if(a%2) cout << y << endl;
        else cout << -1 << endl;
        return;
    }

    int ans = 0;
    for(int i=a;i<b;i++){
        if(i%2) ans += x;
        else ans += min(x, y);
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