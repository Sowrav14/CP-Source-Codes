#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    int x = 1, y = 2;
    int vol = 9;
    for(int i=3;i<=n;i++){
        int z = x + y;
        x = y;
        y = z;

        vol += (z * z * z);
    }

    for(int i=1;i<=m;i++){
        int l, r, h; cin >> l >> r >> h;
        if(l * r * h >= vol && min({l, r, h}) >= y && max({l, r, h}) >= x + y){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;

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