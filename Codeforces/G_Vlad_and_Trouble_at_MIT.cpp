#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;

vector<int>g[N];
int vis[N];
string s;


int dfs(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}



void solve(){

    int n; cin >> n;
    for(int i=2;i<=n;i++){
        int x; cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    cin >> s;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}