#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    if(k > n) return cout << 1 << endl, void();
    vector<int> v(n+10, 0);
    for(int i=1;i<=k;i++) v[i] = 1;
    int l = 1, sum = k%M;
    for(int i=k+1;i<=n+1;i++){
        v[i] = sum;
        sum = (sum%M - v[l]%M + M)%M;
        l++;
        sum = (sum%M + v[i]%M)%M;
    }
    // for(int i=1;i<=n;i++) cout << v[i] << " "; cout << endl;
    cout << v[n+1] << endl;

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