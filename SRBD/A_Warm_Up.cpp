#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    // cout << n << endl;
    vector<pair<int,pair<int,int>>> v;
    map<int,int> m;
    // for(int i=1;i<=n;i++){
    //     int x, y; cin >> x >> y;
    //     v.push_back({y, {x, i}});
    //     m[x] = i;
    // }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        m[x] = i;
        v.push_back({0, {x, i}});
    }
    for(int i=0;i<n;i++){
        int y; cin >> y;
        v[i].first = y;
    }
    sort(v.begin(), v.end());
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        int y = v[i].first;
        int x = v[i].second.first;
        int id = v[i].second.second;
        if(x == y) continue;
        // cout << x << " --- " << y << endl;
        if(y < x or m.count(y) == 0) {
            cout << -1 << endl;
            return;
        }
        int xx = m[y];
        ans.push_back({id, xx});
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i.first << " " << i.second << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}