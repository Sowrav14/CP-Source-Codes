#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    int deg = 0;
    vector<int> a(n+1, 0);
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        a[u]++, a[v]++;
        deg = max({deg, a[u], a[v]});
    }
    if(deg <= 2){
        cout << 2 * n - 1 << endl;
    } else {
        cout << n + 1 << endl;
    }

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