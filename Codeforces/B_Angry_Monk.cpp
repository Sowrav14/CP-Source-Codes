#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,k; cin >> n >> k;
    vector<int>v(k);
    for(int i=0;i<k;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=0;i<k-1;i++){
        ans += (v[i] - 1) + v[i];
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}