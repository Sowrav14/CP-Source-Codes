#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// time 2:04

void solve(){

    int n; cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        m[x]++;
    }

    int ans = 1;
    for(int i=1;i<=n;i++){
        int f = 0;
        for(auto j : m){
            if(j.second >= i) f++;
        }
        ans = max(ans, i * f);
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