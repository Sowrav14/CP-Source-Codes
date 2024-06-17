#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<pair<char,set<int>>> g;
set<int> to_remove;
vector<int>d;

void bfs(int source){
    queue<int>q;
    q.push(source);
    d[source] = 0;
    to_remove.erase(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        vector<int>adj;
        if(g[u].first == 'N'){
            for(auto v : g[u].second){
                if(to_remove.count(v)){
                    adj.push_back(v);
                }
            }
        } else{
            for(auto v : to_remove){
                if(!g[u].second.count(v)){
                    adj.push_back(v);
                }
            }
        }

        for(auto v : adj){
            q.push(v);
            d[v] = d[u] + 1;
            to_remove.erase(v);
        }
    }
}


void solve(){

    int n,s,t; cin >> n >> s >> t;
    g.resize(n+10); d.resize(n+10, -1);
    for(int i=0;i<n;i++){
        to_remove.insert(i);
        char c; cin >> c;
        int m; cin >> m;
        set<int>temp;
        for(int j=0;j<m;j++){
            int x; cin >> x;
            temp.insert(x);
        }
        g[i] = {c, temp};
    }

    bfs(s);

    if(d[t] == -1){
        cout << "impossible" << endl;
    } else {
        cout << d[t] << endl;
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