#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000+10;
char grid[N][N];
int vis[N][N];
int n,m;
pair<int,int> st, en;
pair<int,int> p[N][N];
queue<pair<int,int>>q;

void next_node(int i, int j, pair<int,int>par){
    if(i>n or j>m or i<1 or j<1) return;
    if(vis[i][j]) return;
    if(grid[i][j] == '#') return;

    q.push({i, j});
    vis[i][j] = 1;
    p[i][j] = par;
}

void bfs(){
    q.push({st.first, st.second});
    vis[st.first][st.second] = 1;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        pair<int,int>par = {i, j};

        next_node(i+1, j, par);
        next_node(i, j+1, par);
        next_node(i-1, j, par);
        next_node(i, j-1, par);
    }
}


void solve(){

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
            p[i][j] = {-1, -1};
            if(grid[i][j] == 'A'){
                st.first = i;
                st.second = j;
            }
            if(grid[i][j] == 'B'){
                en.first = i;
                en.second = j;
            }
        }
    }

    bfs(); 

    if(!vis[en.first][en.second]) {
        cout << "NO" << endl;
        return;
    }

    string path = "";
    int i = en.first, j = en.second;
    while(1){
        int pi = p[i][j].first;
        int pj = p[i][j].second;

        if(i == pi + 1){
            path += 'D';
        } else if(i == pi - 1){
            path += 'U';
        } else if(j == pj + 1){
            path += 'R';
        } else{
            path += 'L';
        }

        if(pi == st.first and pj == st.second) break;
        i = pi, j = pj;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;

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