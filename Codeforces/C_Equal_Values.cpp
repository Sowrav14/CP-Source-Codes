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

    vector<int> pre(n);
    for(int i=1;i<n;i++){
        if(a[i] == a[i-1]){
            pre[i] = pre[i-1];
        } else {
            pre[i] = a[i] * i;
        }
    }

    vector<int> suf(n);
    for(int i=n-2;i>=0;i--){
        if(a[i] == a[i+1]){
            suf[i] = suf[i+1];
        } else {
            suf[i] = a[i] * (n - i - 1);
        }
    }

    int ans = pre[0] + suf[0];
    for(int i=1;i<n;i++){
        ans = min(ans, pre[i] + suf[i]);
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