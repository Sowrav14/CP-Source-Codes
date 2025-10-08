#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    int k = 1000000000ll;
    vector<int> x(n), y(n);
    int mn1 = LLONG_MAX;
    int mn2 = LLONG_MAX;
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        mn1 = min(mn1, x[i] + y[i]);
        mn2 = min(mn2, y[i] - x[i]);
    }

    int p;
    // move the the left-bottom corner
    cout << "? L " << k << endl;
    cin >> p;
    cout << "? L " << k << endl;
    cin >> p;
    cout << "? D " << k << endl;
    cin >> p;
    cout << "? D " << k << endl;
    cin >> p;

    // Move bottom-right corner
    int q;
    for(int i = 0; i < 4; i++) {
        cout << "? R " << k << endl;
        cin >> q;
    }

    int a = 4 * k + mn1 - p;
    int b = q - 4 * k - mn2;
    int alpha = (a + b) / 2;
    int beta = (a - b) / 2;
    cout << "! " << alpha << " " << beta << endl;

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