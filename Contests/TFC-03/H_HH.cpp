#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;



void solve(){

    int c, n; cin >> c >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = -50;
    for(int i=50;i>=-50;i--){
        bool f = true;
        int x = 0;
        for(int j=0;j<n;j++){
            x++;
            if(v[j] >= i) {
                x = 0;
            }
            if(x > c){
                if(v[j] < i) {
                    f = 0;
                    break;
                } else {
                    x = 0;
                }
            }
        }
        // if(f) cout << i << endl;
        if(f) ans = max(ans, i);
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