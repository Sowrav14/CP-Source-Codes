#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

bool check(int a, int b){
    if(a > b) swap(a, b);

    int x = ceil(b / 2.0);
    if(a < x - 1) return false;
    // if(a > x + 1) return false;
    return true;
}

void solve(){

    int a, b, c , d; cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if(check(a, b) and check(c, d)) cout << "YES\n";
    else cout << "NO\n";

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