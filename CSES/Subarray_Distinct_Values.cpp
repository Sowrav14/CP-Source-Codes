#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,k; cin >> n >> k;
    vector<int>v(n+1, 0); for(int i=1;i<=n;i++) cin >> v[i];
    map<int,int>m;
    int l = 1, r = 1, dis = 0, ans = 0;
    while(r <= n){
        if(m[v[r]] == 0) dis++;
        m[v[r]]++;
        while(dis > k){
            m[v[l]]--;
            if(m[v[l]] == 0) dis--;
            l++;
        }
        ans += (r - l + 1);
        r++;
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