#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int x, y; cin >> x >> y;
    if(y > x) {
        cout << 2 << endl;
    } else{
        if(y == 1) {
            cout << -1 << endl;
            return;
        }
        x -= 1;
        if(x > y) {
            cout << 3 << endl;
        } else {
            cout << -1 << endl;
        }
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