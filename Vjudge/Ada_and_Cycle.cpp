#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2000+10;
vector<int>g[N];
int n;

int bfs(int s){
    vector<int> dis(n+1, 0), vis(n+1, 0);
    queue<int>q;
    for(auto v : g[s]){
        q.push(v);
        dis[v] = 1;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(dis[v] == 0){
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    return dis[s];
}


void solve(){

    cin >> n;
    vector<int>ans(n+1, -1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin >> x;
            if(x == 1){
                g[i].push_back(j);
                if(i == j) ans[i] = 1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(ans[i] == 1){
            cout << 1 << endl;
            continue;
        }
        int d = bfs(i);
        if(d == 0) cout << "NO WAY" << endl;
        else cout << d << endl;
    }

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