#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<pair<int,int>>tasks;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        tasks.push_back({x, y});
    }
    sort(tasks.begin(), tasks.end(), [](pair<int,int>a, pair<int,int>b){
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });
    // for(auto i : tasks) cout << i.first << " " << i.second << endl;
    int last = 0, ans = 0;
    for(auto i : tasks){
        int x = i.first;
        int y = i.second;

        if(x >= last){
            last = y;
            ans++;
        }
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}