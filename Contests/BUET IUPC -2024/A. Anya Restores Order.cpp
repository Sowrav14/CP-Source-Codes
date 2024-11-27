#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Tube {
    bool f = 1;
    set<int>s;
    int mex;
};

Tube *tube[N];

void solve(){

    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++) tube[i] = new Tube();

    for(int i=1;i<=n;i++){
        int m; cin >> m;
        for(int j=1;j<=m;j++){
            int x; cin >> x;
            tube[i]->s.insert(x);
        }

        tube[i]->mex = 1;
        while(!tube[i]->s.empty() and *tube[i]->s.begin() == tube[i]->mex){
            tube[i]->s.erase(tube[i]->s.begin());
            tube[i]->mex++;
        }
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, v; cin >> u >> v;
            if(tube[u]->s.size() > tube[v]->s.size()) swap(tube[u], tube[v]);
            assert(tube[u]->f);
            assert(tube[v]->f);

            tube[v]->mex = max(tube[u]->mex, tube[v]->mex);
            for(auto i : tube[u]->s) tube[v]->s.insert(i);

            tube[u]->s.clear(); tube[u]->f = 0;

            while(!tube[v]->s.empty() and *tube[v]->s.begin() < tube[v]->mex)
                tube[v]->s.erase(tube[v]->s.begin());
            
            while(!tube[v]->s.empty() and *tube[v]->s.begin() == tube[v]->mex){
                tube[v]->s.erase(tube[v]->s.begin());
                tube[v]->mex++;
            }
        } else {
            int x; cin >> x;
            assert(tube[x]->f);
            if(tube[x]->s.empty()) cout << "complete" << endl;
            else cout << tube[x]->mex << endl;
        }
    }

    for(int i=1;i<=n;i++) delete(tube[i]);

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