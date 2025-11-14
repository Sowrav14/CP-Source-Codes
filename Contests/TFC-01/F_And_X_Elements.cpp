#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> suf(n+1, 0);
    suf[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i] = suf[i+1] | a[i];
    }

    int x = 0;
    for(int i=0;i<k;i++){
        x &= a[i];
    }
    int ans = x | suf[k];
    for(int i=k;i<n;i++){
        x &= a[i];
        int res = x | suf[i+1];
        ans = max(ans, res);
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