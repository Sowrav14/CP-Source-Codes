#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int l1, l2, l3, b1, b2, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    // all side by side
    if( l1 == l2 and
        l1 == l3 and 
        l1 == b1 + b2 + b3) return cout << "YES" << endl, void();
    if( b1 == b2 
        and b1 == b3 
        and b1 == l1 + l2 + l3) return cout << "YES" << endl, void();
    
    // two side by side
    if( l1 == l2 + l3 and
        l1 == b1 + b2 and
        l1 == b1 + b3) return cout << "YES" << endl, void();

    if( b1 == b2 + b3 and 
        b1 == l1 + l2 and
        b1 == l1 + l3) return cout << "YES" << endl, void();
    
    cout << "NO" << endl;
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