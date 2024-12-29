#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m, cnt;
int g[N][N], vis[N][N];


void dfs(int i, int j){
    if(i<1 or i>n) return;
    if(j<1 or j>m) return;
    if(g[i][j] == 0) return;
    if(vis[i][j]) return;

    vis[i][j] = 1;
    cnt++;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
    return;
}

void solve(){

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c; cin >> c;
            g[i][j] = (c == '#');
            vis[i][j] = 0;
        }
    }

    int ans1 = 0, ans2 = n * m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                cnt = 0;
                dfs(i, j);
                ans1 += cnt * cnt;
            }
        }
    }

    int g = __gcd(ans1, ans2);
    ans1 /= g;
    ans2 /= g;
    
    if(ans1 == 0) cout << 0 << endl;
    else if(ans2 == 1) cout << ans1 << endl;
    else cout << ans1 << " / " << ans2 << endl;

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