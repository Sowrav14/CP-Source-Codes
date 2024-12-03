#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

double A_pow_B(double a,int b){
    double ret = 1;
    while(b){
        if(b&1) {
            ret = (ret * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return ret;
}

void solve(){

    int m, n; cin >> m >> n;
    double ans = 0;

    for(int i=1;i<=m;i++){
        double x = i / (m * 1.0);
        double y = (i - 1) / (m * 1.0);
        ans += 1.0 * i * A_pow_B(x, n);
        ans -= 1.0 * i * A_pow_B(y, n);
    }

    cout << fixed << setprecision(12) << ans << endl;

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