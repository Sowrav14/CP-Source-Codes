#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e12;

int recur(int i, int j){
    if(i < 1 or j < 1) return inf;
    if(j == 1) return i-j;
    return recur(j, i%j) + i/j;
}

void solve(){

    int n; cin >> n;
    int ans = inf;
    for(int i=n;i>=1;i--){
        ans = min(ans, recur(n, i));
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}