#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, c; cin >> n >> c;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp[a[i]] == 0) mp[a[i]] = b[i];
        else mp[a[i]] = min(mp[a[i]], b[i]);
    }
    vector<pair<int,int>> v;
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int cnt = 0, cost = 0;
    for(auto it : v){
        // cout << it.first << " " << it.second << endl;
        cnt++;
        cost += it.first;
        int res = c * cnt - cost;
        ans = max(ans, res);
    }
    cout << ans << endl;

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