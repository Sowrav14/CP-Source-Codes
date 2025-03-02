#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int>suf(n+1, 0);
    for(int i=n-1;i>=0;i--){
        suf[i] = suf[i+1] + v[i];
    }
    int ans = suf[0];
    for(int i=0;i<n;i++){
        int cur = (i+1) * (i+1) + suf[i+1];
        ans = max(ans, cur);
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