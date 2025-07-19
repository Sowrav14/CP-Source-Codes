/**
 * @file Endoscope.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-17
 * @copyright Copyright (c) 2025
 * @problem:
 * @tag: dfs
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 50 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m, x, y, l;
int grid[N][N];
bool vis[N][N];
bool dfsvisited[N][N];
// pip[i][j] = where the pipe of ith type will go if take direction j.
int pip[][4]={
    {0, 0, 0, 0},
    {-1, 1, -1, 1},
    {0, 0, -1, 1},
    {-1, 1, 0, 0},
    {0, 1, -1, 0},
    {0, 1, 0, 1},
    {-1, 0, 0, 1},
    {-1, 0, -1, 0}
};


void dfs(int i, int j, int l, int &ans){
    // all return conditions.
    if(i < 0 or j < 0 or i >= n or j >= m) return;
    if(grid[i][j] == 0) return;
    if(dfsvisited[i][j]) return;
    if(l <= 0) return;

    // update the state values
    if(!vis[i][j]) ans++;
    dfsvisited[i][j] = 1;
    vis[i][j] = 1;
    
    int left = pip[grid[i][j]][0];
    int right = pip[grid[i][j]][1];
    int up = pip[grid[i][j]][2];
    int down = pip[grid[i][j]][3];

    // go to next
    if(pip[grid[i][j+left]][1] == 1) dfs(i, j + left, l - 1, ans);
    if(pip[grid[i][j+right]][0] == -1)dfs(i, j + right, l - 1, ans);
    if(pip[grid[i+up][j]][3] == 1)dfs(i + up, j, l - 1, ans);
    if(pip[grid[i+down][j]][2] == -1)dfs(i + down, j, l - 1, ans);
    
    // backtrack
    dfsvisited[i][j] = 0;
}

void solve(){

    cin >> n >> m >> x >> y >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            vis[i][j] = 0;
        }
    }
    int ans = 0;
    dfs(x, y, l, ans);
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