#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int x, t; cin >> x >> t;
        v.push_back({x, t});
    }
    sort(v.begin(), v.end());

    int ans = 500;
    for(int i=0;i<n;i++){
        int cur = v[i].first;
        int tim = v[i].second;

        int fw = (tim - 1) / 2;
        ans = min(ans, cur + fw);
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