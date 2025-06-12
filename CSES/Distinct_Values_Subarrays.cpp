#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    int l = 0;
    int ans = 0;
    for(int r=0;r<n;r++){
        if(mp.count(a[r]) == 0){
            mp[a[r]] = 1;
            ans += (r - l + 1);
        } else {
            while(l < r && mp.count(a[r]) > 0){
                mp[a[l]]--;
                if(mp[a[l]] == 0) mp.erase(a[l]);
                l++;
            }
            mp[a[r]] = 1;
            ans += (r - l + 1);
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