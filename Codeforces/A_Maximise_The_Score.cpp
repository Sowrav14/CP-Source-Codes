#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(2*n);
    for(int i=0;i<2*n;i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i=0;i<2*n;i+=2){
        ans += v[i+1];
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