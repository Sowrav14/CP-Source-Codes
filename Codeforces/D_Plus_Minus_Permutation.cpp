#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, x, y; cin >> n >> x >> y;

    int big = (n / x);
    int small = (n / y);

    int lcm = (x * y) / __gcd(x, y);
    big -= (n / lcm);
    small -= (n / lcm);
    // cout << big << " " << small << endl;
    int add = (n * (n + 1)) / 2;
    // cout << add << endl;
    n -= big;
    add -= (n * (n + 1)) / 2;
    add -= (small * (small + 1)) / 2;

    cout << add << endl;

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