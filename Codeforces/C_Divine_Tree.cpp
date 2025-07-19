#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    int x = (n * (n + 1)) / 2;
    if(m > x) return cout << -1 << endl, void();

    vector<pair<int,int>> ans;
    int last = n + 1;
    for(int i=n;i>=2;i--){
        if(x == m) break;
        int y = x - m;
        int z = i - 1;
        if(y > z){
            x -= z;
            ans.push_back({1, i});
        } else {
            x -= y;
            ans.push_back({i-y, i});
        }
        last = i;
    }
    if(x != m) return cout << -1 << endl, void();
    
    for(int i=last-1;i>1;i--){
        ans.push_back({i, i-1});
    }

    cout << last - 1 << endl;
    for(auto [x, y] : ans){
        cout << x << " " << y << endl;
    }

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