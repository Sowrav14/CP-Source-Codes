#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, a, b, x; cin >> n >> a >> b >> x;
    // if(a == x) {
    //     cout << "YA" << endl;
    //     return;
    // }
    
    // int mx = max(a, b);
    // int mn = min(a, b);

    // int req = inf;
    // if(x >= mx){
    //     req = x - mx;
    // } else if(x <= mn) {
    //     req = mn - x;
    // }
    // // cout << req << endl;
    if(a < b) swap(a, b);
    if(x == 0) x = min(x, (b - n));
    int sum = a + b;
    int y = sum - x;
    // y = max(0ll, y);
    if(x < y) swap(x, y);
    // cout << a << " " << b << endl;
    // cout << x << " " << y << endl;
    // cout << abs(x-a) << " " << n  << endl;
    if(x > a  and (x-a == b-y) and (abs(x-a) == n)){
        cout << "YA" << endl;
    } else {
        cout << "TIDAK" << endl;
    }

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