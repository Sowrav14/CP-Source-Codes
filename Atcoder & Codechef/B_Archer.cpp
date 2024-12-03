#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b, c, d; cin >> a >> b >> c >> d;
    double p_first_hit = (a / (b * 1.0));
    double p_both_miss = (1 - (a / (b * 1.0))) * (1 - (c / (d * 1.0)));

    cout << fixed << setprecision(12) << p_first_hit / (1 - p_both_miss) << endl;

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