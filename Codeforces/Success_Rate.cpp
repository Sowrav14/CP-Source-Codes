#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int x,y,p,q; cin >> x >> y >> p >> q;

    int l = 1, r = 1e9+10;
    int ans = -1;
    while(l <= r){
        int m = (l + r) / 2;

        int cp = p * m;
        int cq = q * m;

        int rs = cp - x;
        int rt = cq - y;

        if(rs > rt or rs < 0){
            l = m + 1;
        } else {
            ans = rt;
            r = m - 1;
        }
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