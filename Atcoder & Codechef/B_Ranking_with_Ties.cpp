#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int>rnk(n);
    int r = 1;
    for(int i=100;i>=1;i--){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(v[j] == i){
                rnk[j] = r;
                cnt++;
            }
        }
        r += cnt;
    }

    for(int i=0;i<n;i++) cout << rnk[i] << endl;

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