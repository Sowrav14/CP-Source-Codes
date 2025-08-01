#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back({x, 0});
    }
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i].second = x;
    }

    int ans = 0;
    for(int l=0;l<=100;l++){
        int tot = 0;
        for(int i=0;i<n;i++){
            if(v[i].second <= l){
                if(v[i].first >= 0) tot += v[i].first;
            }
        }
        ans = max(ans, tot - l);
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