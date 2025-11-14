#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;

void solve(){

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    // for(auto i : v) cout << i << " "; cout << endl;
    int l = 1, r = inf;
    int ans = 0;
    while(l <= r){
        int m = (l + r) / 2;
        int x = 0;
        for(int i=0;i<n;i++){
            if(m != 0) x += (v[i] / m);
        }
        if(x < k){
            r = m - 1;
        } else {
            ans = m;
            l = m + 1;
        }
    }
    cout << ans << endl;

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