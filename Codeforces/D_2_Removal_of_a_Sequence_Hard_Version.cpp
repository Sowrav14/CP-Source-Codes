#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int inf = 1e12;

/// 10 2 3
// 10/4 = 2 -> 8
// 8/4 = 2 -> 6
// how many time 2 decreased.
// ((m - q * t) / q) = q
// q <= (m - q*t) / q <= q + 1 
// t = (m - q*y)/q + 1 -> (10 - 2*4) / 2 + 1 = 2


int survivors(int m, int x, int y){
    while(x > 0 && m > 0){
        int q = m / y;
        if(q == 0) break;
        int t = (m - q*y) / q + 1;
        if(t > x) t = x;
        m -= t * q;
        x -= t;
        if(m < y) break;
    }
    return m;
}

void solve(){
    int x, y, k; 
    cin >> x >> y >> k;
    if(y == 1){
        cout << -1 << endl;
        return;
    }

    int l = k, r = inf, ans = -1;
    while(l <= r){
        int m = (l + r) / 2;
        int rem = survivors(m, x, y);
        if(rem >= k){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
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
