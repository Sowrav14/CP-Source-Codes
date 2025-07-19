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
    multiset<int> ms;
    int mx, mn;
    int prev = 0, ans = 0, adder = 1;
    for(int i=0;i<n;i++){
        if(i == 1){
            ans = a[0] + a[1];
        }
        if(i > 1){
            int res = prev + (adder) * a[i];
            ans = min(ans, res);
        }
        if(mn != a[i]) adder = 0;
        mn = i == 0 ? a[i] : min(mn, a[i]);
        mx = i == 0 ? a[i] : max(mx, a[i]);
        prev += mn;
    }
    cout << min(ans, prev) << endl;

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