#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(55, 0);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        v[x]++;
    }

    int ans = 0;
    int zo = min(v[0], v[1]);
    ans += 2 * zo;
    v[0] -= zo;
    v[1] -= zo;
    ans += v[0];
    for(int i=1;i<=50;i++){
        ans += i * v[i];
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