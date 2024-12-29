#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    int R = 0;
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        if(x != i) R = i; 
    }

    double ans = 1.0;
    for(int i=1;i<=m;i++){
        int r; double p; cin >> r >> p;
        if(r < R) continue;
        // cout << r << " " << p << endl;
        ans *= (1 - p);
    }
    if(R == 0) ans = 0;
    cout << fixed << setprecision(10) << (double)(1.0 - ans) << endl;

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