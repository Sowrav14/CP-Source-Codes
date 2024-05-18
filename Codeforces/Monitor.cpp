#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const float eps = 1e-6;
const float e = 1e-9;

void solve(){

    int a,b; cin >> a >> b;
    int x,y; cin >> x >> y;
    int g = __gcd(x, y);
    x /= g;
    y /= g;

    if(a<x or b<y){
        cout << 0 << " " << 0 << endl;
        return;
    }

    int p = a / x; 
    int q = b / y;

    if(b*x > a*y){
        cout << p * x << " " << p * y << endl;
    } else{
        cout << q * x << " " << q * y << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}