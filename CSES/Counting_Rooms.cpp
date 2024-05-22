#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000+10;
char grid[N][N];
int vis[N][N];
int n,m;

void dfs(int i, int j){
    if(i > n or j > m or i < 1 or j < 1) return;
    if(vis[i][j]) return;
    if(grid[i][j] == '#') return;

    vis[i][j] = 1;
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
}


void solve(){

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j] == '#') continue;
            if(vis[i][j]) continue;

            cnt++; dfs(i, j);
            
        }
    }

    cout << cnt << endl;
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