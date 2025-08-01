#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i=1;i<=n;i++) cin >> v[i];
    
    int res, ans;
    res = ans = 1;
    for(int i=2;i<=n;i++) {
        if(v[i] < v[i - 1]) {
            res += i;
        } else {
            res += 1;
        }
        ans += res;
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