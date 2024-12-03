#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int r,g,b; cin >> r >> g >> b;
    string s; cin >> s;
    int ans = INT_MAX;
    if(s != "Red"){
        ans = min(ans, r);
    }
    if(s != "Green"){
        ans = min(ans, g);
    }
    if(s != "Blue"){
        ans = min(ans, b);
    }
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