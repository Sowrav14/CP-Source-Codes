#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n, h; cin >> n >> h;

    for(int i=1;i<=n-1;i++){
        float x = (i / (n * 1.0));
        x = sqrtf(x);
        x = x * h;
        cout << fixed << setprecision(12) << x << endl;
    }

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