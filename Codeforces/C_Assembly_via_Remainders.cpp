#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    int mx = 0;
    vector<int>x(n-1), a(n);
    for(int i=0;i<n-1;i++) {
        cin >> x[i];
        mx = max(mx, x[i]);
    }

    a[0] = mx + 1;
    for(int i=1;i<n;i++){
        a[i] = a[i-1] + x[i-1];
    }

    for(int i=0;i<n;i++) cout << a[i] << " "; cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}