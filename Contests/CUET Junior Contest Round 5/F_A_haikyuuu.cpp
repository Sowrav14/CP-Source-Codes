#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int x, y, u, v; cin >> x >> y >> u >> v;
    double a = v * v - u * u;
    double b = 2 * y * u;
    double c = 0 - ( x * x + y * y);
    // cout << a << " " << b << " " << c << endl;
    if(a == 0){
        // double t = -c / b;
        // cout << fixed << setprecision(10) << t * u << endl;
        cout << -1 << endl;
        return;
    }

    double d = b * b - 4 * a * c;
    if(d < 0) cout << -1 << endl;
    else {
        double t1 = (-b + sqrt(d)) / (2 * a);
        double t2 = (-b - sqrt(d)) / (2 * a);
        if(t1 > 0){
            cout << fixed << setprecision(10) << t1 * u << endl;
        }
        else if(t2 > 0){
            cout << fixed << setprecision(10) << t2 * u << endl;
        }
        else {
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