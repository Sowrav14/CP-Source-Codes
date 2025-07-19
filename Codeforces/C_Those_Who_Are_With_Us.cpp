#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<vector<int>>g(n, vector<int>(m));

    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
            mx = max(mx, g[i][j]);
        }
    }

    vector<int> goc(mx+1, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            goc[g[i][j]]++;
        }
    }

    vector<vector<int>> roc(n, vector<int>(mx+1, 0));
    vector<vector<int>> coc(m, vector<int>(mx+1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            roc[i][g[i][j]]++;
            coc[j][g[i][j]]++;
        }
    }

    int res = mx;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x = g[i][j];
            int ans = 0;
            for(int val=1;val<=mx;val++){
                int currowoc = roc[i][val];
                int curcoloc = coc[j][val];
                int gloc = goc[val];
                gloc -= currowoc;
                gloc -= curcoloc;

                if(val == x){
                    gloc++;
                }
                if(gloc > 0) ans = val;
                else ans = val - 1;
            }
            res = min(ans, res);
        }
    }
    cout << res << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    // cout << t << endl;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}