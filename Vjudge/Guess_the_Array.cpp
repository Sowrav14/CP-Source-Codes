#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    cout << "? " << 1 << " " << 2 << endl;
    cout << endl;
    int a; cin >> a;
    cout << "? " << 1 << " " << 3 << endl;
    cout << endl;
    int b; cin >> b;
    cout << "? " << 2 << " " << 3 << endl;
    cout << endl;
    int c; cin >> c;

    vector<int>v(n+1);
    // 2*v[1] + (v[2] + v[3]) = r1 + r2;
    // v[1] = (r1 + r2 - r3)/2
    v[1] = (a + b - c) / 2;
    v[2] = a - v[1];
    v[3] = b - v[1];

    for(int i=4;i<=n;i++){
        cout << "? " << 1 << " " << i << endl;
        cout << endl;
        int x; cin >> x;
        v[i] = x - v[1];
    }
    cout << "! ";
    for(int i=1;i<=n;i++){
        cout << v[i] << " ";
    }
    cout << endl;

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