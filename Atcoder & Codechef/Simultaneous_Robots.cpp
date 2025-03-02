#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m;
vector<string>grid;
vector<vector<int>>vis;

void dfs(int i, int j, int t){
    if(i+1 > n) return;
    if(j+1 > m) return;
    if(grid[i][j] == '#') return;
    if(vis[i][j] != -1) return;

    vis[i][j] = t;
    dfs(i+1, j, t+1);
    dfs(i, j+1, t+1);
}

vector<vector<int>>vis2;
bool dfs2(int i, int j, int t, int pass){
    if(i+1 > n) return false;
    if(j+1 > m) return false;
    if(grid[i][j] == '#') return false;
    if(vis2[i][j] != -1) return false;
    if(vis[i][j] != t) return false;

    vis2[i][j] = pass;
    int flag = false;
    if(i == n-1 and j == m-1) flag = true; 
    if(!flag or pass) flag |= dfs2(i+1, j, t+1, pass);
    if(!flag or pass) flag |= dfs2(i, j+1, t+1, pass);
    if(flag == false and pass == 0){
        vis2[i][j] = -1;
    }
    return flag;
}

void solve(){

    cin >> n >> m;
    grid.clear();
    vis.clear();
    vis.resize(n, vector<int>(m, -1));
    vis2.clear();
    vis2.resize(n, vector<int>(m, -1));
    // vector<string>grid;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        grid.push_back(s);
    }

    dfs(0, 0, 0);
    // cout << vis[n-1][m-1] << endl;
    if(vis[n-1][m-1] == -1){
        cout << -1 << endl;
        return;
    }
    // path(n-1, m-1);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << vis[i][j] << " ";
    //     } cout << endl;
    // }
    dfs2(0, 0, 0, 0);
    vis2[0][0] = -1;
    vis2[n-1][m-1] = -1;
    dfs2(0, 0, 0, 1);
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << vis2[i][j] << " ";
    //     } cout << endl;
    // }

    // cout << vis2[n-1][m-1] << endl;

    if(vis2[n-1][m-1] == 1){
        cout << vis[n-1][m-1] << endl;
    } else {
        cout << vis[n-1][m-1] + 2 << endl;
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