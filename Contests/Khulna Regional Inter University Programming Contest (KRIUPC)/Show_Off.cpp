#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e18;


void solve(){

    int n, h; cin >> n >> h;
    vector<int>a(n+2, 0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int>v = a;
    vector<int>pref(n+2, 0), suf(n+2, 0);
    for(int i=1;i<=n;i++){
        int cur;
        if(v[i] > v[i-1]) cur = 0;
        else {
            cur = (v[i-1] - v[i] + 1);
            v[i] = v[i] + cur;
        }
        pref[i] = pref[i-1] + cur;
    }
    vector<int> u = a;
    for(int i=n;i>=1;i--){
        int cur;
        if(u[i] > u[i+1]) cur = 0;
        else {
            cur = (u[i+1] - u[i] + 1);
            u[i] = u[i] + cur;
        }
        suf[i] = suf[i+1] + cur;
    }

    // for(int i=1;i<=n;i++) cout << pref[i] << " \n"[i == n];
    // for(int i=1;i<=n;i++) cout << suf[i] << " \n"[i == n];

    int ans = inf;
    for(int i=2;i<n;i++){
        if(v[i-1] < h and u[i+1] < h and a[i] <= h){
            ans = min(ans, pref[i-1] + suf[i+1] + h - a[i]);
        }
    }
    cout << (ans >= inf ? -1 : ans) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}