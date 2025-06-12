#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());
    int g = 0;
    for(int i=1;i<n;i++){
        if(a[i]%a[0] == 0) g = __gcd(g, a[i]);
    }
    cout << (g == a[0] ? "Yes" : "No") << endl;

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