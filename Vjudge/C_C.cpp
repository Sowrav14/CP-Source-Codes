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
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x, y; cin >> x >> y;
        int a = x - y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        int x = a.first - a.second;
        int y = b.first - b.second;
        if(x == y) return a.second < b.second;
        return x > y;
    });

    int ans = 0;
    int cur = 0;
    for(int i=0;i<n;i++){
        if(cur < v[i].first){
            ans += v[i].first - cur;
            cur = v[i].first;
        }
        cur -= v[i].second;
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