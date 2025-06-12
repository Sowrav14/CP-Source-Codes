#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m, k; cin >> n >> m >> k;
    int fa = n / (m + 1);
    int mod = fa;
    if(fa < k){
        mod = k;
    }

    for(int i=0;i<n;i++) cout << (i%mod) << " \n"[i == n-1];

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