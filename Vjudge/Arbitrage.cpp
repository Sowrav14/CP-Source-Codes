#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1010;
float g[N][N];


void Floyd_Warshall(int n){
    for(int k=1;k<=n;++k) {
        for(int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
            }
        }
    }
}


signed main(){
    Fast_IO()
    int cases = 0;
    int n,m;
    while(cin >> n){
        cases++;
        if(n == 0) return 0;

        map<string, int>mp;
        for(int i=1;i<=n;i++){
            string s; cin >> s;
            mp[s] = i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j] = 0.0;
            }
        }

        cin >> m;
        for(int i=0;i<m;i++){
            string u, v; float w;
            cin >> u >> w >> v;
            g[mp[u]][mp[v]] = w;
        }
        Floyd_Warshall(n);

        int flag = false;
        for(int i=1;i<=n;i++){
            if(g[i][i] > 1){
                flag = true;
            }
        }
        cout << "Case " << cases << ": " << (flag ? "Yes" : "No") << endl;
    }
}