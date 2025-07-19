#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n), p(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) p[i] = (a[i] * b[i]) / __gcd(a[i], b[i]);

    int g = 0;
    for(int i=0;i<n;i++){
        g = __gcd(p[i], g);
        if(g != a[i]){
            return cout << "NO" << endl, void();
        }
    }

    g = 0;
    for(int i=n-1;i>=0;i--){
        g = __gcd(p[i], g);
        if(g != b[i]){
            return cout << "NO" << endl, void();
        }
    }

    cout << "YES" << endl;

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