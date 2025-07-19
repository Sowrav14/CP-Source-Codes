#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<pair<int,int>> ex;
    for(int i=0;i<m;i++){
        int x, y; cin >> x >> y;
        ex.push_back({x, y});
    }
    sort(ex.begin(), ex.end(), [](pair<int,int>a, pair<int,int>b){
        return a.first - a.second < b.first - b.second;
    });
    int ans = 0;
    for(int i=0;i<m;i++){
        int a = ex[i].first, b = ex[i].second;
        int temp = n;
        int t = 0;
        if (temp >= a) {
            int d = a - b;
            t = (temp - b) / d;
            temp = temp - t * (a - b);
        }
        ans += t;
        n = temp;
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