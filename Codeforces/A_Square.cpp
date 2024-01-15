#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    vector<pair<int,int>>v(4);
    for(int i=0;i<4;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int sq = (v[0].first-v[1].first) * (v[0].first-v[1].first) + (v[0].second-v[1].second)*(v[0].second-v[1].second);

    cout << sq << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}