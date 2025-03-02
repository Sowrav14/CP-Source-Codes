#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m;
    string a, b; cin >> a >> b;
    n = a.size();
    m = b.size();

    vector<int>vis(n, 0);
    int i = n - 1, j = m - 1;
    while(i>=0 and j>=0){
        // cout << i << " " << j << endl;
        if(a[i] == b[j]){
            vis[i] = 1;
            i--;
            j--;
        } else {
            i--;
        }
    }

    if(j != -1){
        // no match found
        cout << -1 << endl;
        return;
    }

    // for(int i=0;i<n;i++) cout << vis[i] << " "; cout << endl;
    int ans = 0;
    int cur = 1;
    for(int i=0;i<n;i++){
        if(vis[i] == 0) ans += cur;
        else cur += 1;
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