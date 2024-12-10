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

    vector<int>oc(7, -1);
    int sum = 0, ans = 0;
    oc[0] = 0;
    for(int i=0;i<n;i++){
        sum += v[i];

        sum %= 7;

        if(oc[sum] == -1){
            oc[sum] = i + 1;
        } else {
            ans = max(ans, i + 1 - oc[sum]);
        }
    }
    cout << ans << endl;

}


signed main(){
    freopen("div7.in","r",stdin);
	freopen("div7.out","w",stdout);
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}