#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>a(n), b(n);
    int mn = 0, mx = 0;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        mn += a[i];
        mx += b[i];
    }

    int ans = mn;
    if(0 < mn or 0 > mx){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for(int i=0;i<n;i++){
        int diff = b[i] - a[i];
        int req = 0 - ans;
        int inc = min(diff, req);
        a[i] += inc;
        ans += inc;
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    } cout << endl;

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