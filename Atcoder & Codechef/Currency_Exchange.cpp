#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b; cin >> a >> b;
    int x, y; cin >> x >> y;
    int t = a * 5 + b - x * 5 - y;

    if(t < 0) return cout << "No" << endl, void();
    if(t % 6 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

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