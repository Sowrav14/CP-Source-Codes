#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    int lx, ly, rx, ry; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'S'){
                lx = i, ly = j;
            }
            if(grid[i][j] == 'G'){
                rx = i, ry = j;
            }
        }
    }

    queue<pair<int, pair<int,int>>> q;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));
    q.push({lx, {ly, 0}});
    dist[lx][ly][0] = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second.first;
        int p = q.front().second.second;
        q.pop();

        if(i == rx and j == ry){
            cout << dist[i][j][p] << "\n";
            return;
        }

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto dir : directions){
            int ni = i + dir.first;
            int nj = j + dir.second;

            if(ni < 0 or ni >= n or nj < 0 or nj >= m) continue;
            if(grid[ni][nj] == '#') continue;

            if(grid[ni][nj] == 'o' and p == 1) continue;
            if(grid[ni][nj] == 'x' and p == 0) continue;

            int np = grid[ni][nj] == '?' ? 1 - p : p;
            if(dist[ni][nj][np] == -1){
                dist[ni][nj][np] = dist[i][j][p] + 1;
                q.push({ni, {nj, np}});
            }
        }
    }
    cout << -1 << "\n";

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