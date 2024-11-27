#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    double n, k; cin >> n >> k;
    double d, x, y; cin >> d >> x >> y;

    if(y <= x){
        cout << (d / x) << endl;
    } else if(k >= n){
        cout << (d / y) << endl;
    } else {
        double boat = k * (d / y);
        double swim = (n - k) * (d / x);
        double avg = (boat + swim) / n;
        cout << fixed << setprecision(10) << avg << endl;
    }

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