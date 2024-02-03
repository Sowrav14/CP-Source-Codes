#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=n-1;i>=1;i--){
        int l = 0, r = i-1;
        while(l<r){
            if(v[l]+v[r] > v[i] and v[l]+v[i]>v[r] and v[r]+v[i]>v[l]){
                ans += r-l;
                r--;
            } else {
                l++;
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
        // cout << "Case " << t << ": ";
        solve();
    }
}