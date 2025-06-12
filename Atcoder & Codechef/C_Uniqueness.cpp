#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    map<int,int>oc;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        v[i] = x;
        oc[x]++;
    }

    int ans = -1, great = -1;
    for(int i=1;i<=n;i++){
        if(oc[v[i]] == 1){
            if(v[i] > great){
                great = v[i];
                ans = i;
            }
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