#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int mn = v[0];

    for(int i=1;i<n;i++){
        if(mn == 0){
            if(v[i] != 0){
                cout << "NO" << endl;
                return;
            }
        } else if(v[i] > 2ll * mn - 1){
            cout << "NO" << endl;
            return;
        }
        mn = min(mn, v[i]);
    }

    cout << "YES" << endl;

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