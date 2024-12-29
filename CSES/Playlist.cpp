#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    set<int>s{v[1]};
    int l = 1, r = 2, ans = 1;
    while(r <= n){
        if(s.size() > ans) ans = s.size();
        if(s.find(v[r]) != s.end()){
            // ans = max(ans, r - l);
            while(v[l] != v[r]){
                s.erase(v[l]);
                l++;
            }
            s.erase(v[l]); l++;
            // cout << l << " " << r << " " << v[r] << endl;
        }
        s.insert(v[r]);
        r++;
    }
    if(s.size() > ans) ans = s.size();
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