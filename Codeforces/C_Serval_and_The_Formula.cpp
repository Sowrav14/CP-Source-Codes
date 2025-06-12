#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int x, y; cin >> x >> y;
    if((x+y) == (x^y)){
        cout << 0 << endl;
        return;
    }
    if(x == y){
        cout << -1 << endl;
        return;
    }

    int m = (1ll << 50);
    cout << m - max(x, y) << endl;

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