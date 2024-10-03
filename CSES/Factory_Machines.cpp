#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n,k; cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    // define the suitable r.
    int l = 0, r = *min_element(v.begin(), v.end()) * k;
    int ans = 0;
    while(l <= r){
        int m = (r-l)/2 + l;    // avoid overflow here.
        int p = 0;
        for(int i=0;i<n;i++){
            p += (1ll * m / v[i]);
            if(p > k) break;    // avoid overflow here also.
        }
        if(p >= k){
            ans = m;
            r = m - 1;
        } else{ 
            l = m + 1;
        }
    }
    cout << ans << endl;

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