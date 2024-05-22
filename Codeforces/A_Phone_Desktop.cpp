#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int x,y; cin >> x >> y;

    int ans = ceil(y / 2.0);
    int rem = ans * 7;
    if(y%2) rem += 4;
    if(x > rem){
        x -= rem;
        x = ceil(x / 15.0);
        ans += x;
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