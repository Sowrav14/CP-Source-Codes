#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    int x = pow(10, k);
    int ans = 1;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        int newans = (ans%x * a%x)%x;
        if(newans % a == 0 and newans / a == ans){
            ans = newans;
        } else {
            ans = 1;
        }
    }
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