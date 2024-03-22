#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int med = ceil(n/2.0);
    int val = v[med];
    // cout << med << " " << val << endl;
    int ans = 0;
    for(int i=med;i<=n;i++){
        // cout << i << " " << v[i] << endl;
        if(v[i] == val){
            ans++;
        } else {
            break;
        }
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