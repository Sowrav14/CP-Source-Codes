#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    bool f = 0;
    if(1ll * x1 * x2 <= 0) f = 1;
    if(1ll * y1 * y2 <= 0) f = 1;
    cout << f << endl;

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