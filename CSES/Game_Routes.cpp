// #include<bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// const int N = 1e5 + 10;
// const int M = 1e9 + 7;
// vector<int>g[N];
// int in[N], dp[N];
// int n,m;



// void solve(){

//     cin >> n >> m;
//     for(int i=0;i<m;i++){
//         int u,v; cin >> u >> v;
//         g[u].push_back(v);
//         in[v]++;
//     }
//     queue<int>top;
//     for(int i=1;i<=n;i++){
//         if(in[i] == 0) top.push(i);
//     }
//     dp[1] = 1;
//     while(!top.empty()){
//         int u = top.front(); top.pop();
//         for(auto v : g[u]){
//             dp[v] = (dp[v] + dp[u]) % M;
//             in[v]--;
//             if(in[v] == 0){
//                 top.push(v);
//             }
//         }
//     }

//     cout << dp[n] << endl;
    
// }


// signed main(){
//     Fast_IO()
//     int t = 1;
//     // cin >> t;
//     for(int i=1;i<=t;i++){
//         // cout << "Case " << t << ": ";
//         solve();
//     }
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
vector<int>g[N];
int vis[N], way[N];
int n,m;
 
int dfs(int u){
    vis[u] = 1;
    if(u == n) return way[n] = 1;
    int ret = 0;
    for(auto v : g[u]){
        if(vis[v] == 0){
            ret += dfs(v);
        } else{
            ret += way[v];
        }
    }
    return way[u] = (ret % M);
}
 
void solve(){
 
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
    }
 
    cout << dfs(1) << endl;
 
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