#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b, k; cin >> a >> b >> k;
    int g = __gcd(a, b);
    a /= g;
    b /= g;

    bool flag = 1;
    if(a > k) flag = 0;
    if(b > k) flag = 0;

    if(flag){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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