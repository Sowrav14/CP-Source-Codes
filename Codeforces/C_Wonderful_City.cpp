#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e16;

int grid[1010][1010];
vector<int> r, c;
int rc[1010], cc[1010];

int recur(int i, int f, vector<int> &v, vector<int> &cost){
    if(i == v.size()) return 0;
    int ans = inf;
    if(i-1>=0 and abs(v[i] - v[i-1]) == 1){
        if(f == 1){
            ans = min(ans, recur(i+1, 0, v, cost));
        }
        else{
            ans = min(ans, recur(i+1, 1, v, cost) + cost[v[i]]);
        }
    } else {
        ans = min(ans, recur(i+1, 0, v, cost));
        ans = min(ans, recur(i+1, 1, v, cost) + cost[v[i]]);
    }
    return ans;
}

void solve(){

    r.clear(); c.clear();
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }

    set<int> row, col;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i+1 <= n && grid[i][j] == grid[i+1][j]){
                row.insert(i);
                row.insert(i+1);
            }
            if(j+1 <= n && grid[i][j] == grid[i][j+1]){
                col.insert(j);
                col.insert(j+1);
            }
        }
    }
    for(auto i : row) r.push_back(i);
    for(auto i : col) c.push_back(i);
    for(int i=1;i<=n;i++) cin >> rc[i];
    for(int i=1;i<=n;i++) cin >> cc[i];

    for(auto i : r) cout << i << " "; cout << endl;
    for(auto i : c) cout << i << " "; cout << endl;

    int ans = 0;
    if(r.size() > 0){
        vector<int> cost(n+1, 0);
        for(int i=1;i<=n;i++){
            cost[i] = rc[i];
        }
        int rcost = recur(0, 0, r, cost);
        ans += rcost;
        cout << rcost << endl;
    }
    if(c.size() > 0){
        vector<int> cost(n+1, 0);
        for(int i=1;i<=n;i++){
            cost[i] = cc[i];
        }
        int ccost = recur(0, 0, c, cost);
        ans += ccost;
        cout << ccost << endl;
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