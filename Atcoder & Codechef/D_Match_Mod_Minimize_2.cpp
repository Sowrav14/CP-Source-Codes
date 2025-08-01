#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] %= m;
    }
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        // map every b[i] with feasible a[i] and calculate answer.
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