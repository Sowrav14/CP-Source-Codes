#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 2e5 + 10;
vector<int>g[N];
int vis[N];
int weight[N];

int sum = 0;

void dfs(int u, int tot, int cnt){
    if(cnt <= 0) return;
    vis[u] = 1;
    int cur = tot + weight[u] * cnt;
    sum = max(sum, cur);
    tot += weight[u];
    cnt--;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v, tot, cnt);
        }
    }
}


void reset(int n){
    for(int i=1;i<=n;i++){
        g[i].clear();
        vis[i] = 0;
        weight[i] = 0;
    }
}



void solve(){

    int n,k; cin >> n >> k;
    int b,s; cin >> b >> s;
    reset(n);

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        g[i].push_back(x);
    }

    for(int i=1;i<=n;i++){
        cin >> weight[i];
    }
    sum = 0;
    dfs(b, 0, k);
    int bodya = sum;

    sum = 0;
    for(int i=1;i<=n;i++) vis[i] = 0;
    dfs(s, 0, k);
    int sasha = sum;

    if(bodya > sasha){
        cout << "Bodya" << endl;
    } else if(sasha > bodya){
        cout << "Sasha" << endl;
    } else{
        cout << "Draw" << endl;
    }

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