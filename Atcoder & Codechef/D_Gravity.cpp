#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, w; cin >> n >> w;
    vector<vector<pair<int,int>>>block(w+1);
    int mx = 0;
    for(int i=1;i<=n;i++){
        int x, y; cin >> x >> y;
        block[x].push_back({y, i});
        if(block[x].size() > mx){
            mx = block[x].size();
        }
    }

    for(int i=1;i<=w;i++){
        sort(block[i].begin(), block[i].end());
        while(block[i].size() < mx){
            block[i].push_back({inf, inf});
        }
        // for(auto [x, id] : block[i]) cout << x << " " << id << endl; cout << endl;
    }

    vector<int>level(n+10, 0);
    for(int i=1;i<=w;i++){
        for(int j=0;j<block[i].size();j++){
            int y = block[i][j].first;
            if(y == inf){
                level[j+1] = -1;
            } else if(level[j+1] != -1) {
                level[j+1] = max(level[j+1], y);
            }
        }
    }
    vector<int>ans(n+1, -1);
    for(int i=1;i<=w;i++){
        for(int j=0;j<block[i].size();j++){
            int y = block[i][j].first;
            int id = block[i][j].second;

            if(y != inf){
                ans[id] = level[j+1];
            }
        }
    }

    // for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;
    int q; cin >> q;
    while(q--){
        int t, id; cin >> t >> id;
        if(ans[id] == -1){
            cout << "Yes" << endl;
        } else if(ans[id] > t){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

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