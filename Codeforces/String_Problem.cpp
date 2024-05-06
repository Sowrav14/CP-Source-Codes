#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int g[26][26];


void warshall(){
    for (int k=0;k<26;k++) {
        for (int i=0;i<26;i++) {
            for (int j=0;j<26;j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}


void solve(){

    string a,b; cin >> a >> b;
    int n; cin >> n;

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            g[i][j] = (i == j ? 0 : 1000000);
        }
    }

    for(int i=0;i<n;i++){
        char u, v; cin >> u >> v;
        int w; cin >> w;
        g[u-'a'][v-'a'] = min(g[u-'a'][v-'a'], w);
    }

    warshall();

    if(a.size() != b.size()){
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i]) continue;

        int w = 100000;
        char c;
        for(int j=0;j<26;j++){
            int x = g[a[i]-'a'][j];
            int y = g[b[i]-'a'][j];
            if(x+y < w){
                w = x + y;
                c = j + 'a';
            }
        }
        if(w == 100000) {
            cout << -1 << endl;
            return;
        }
        a[i] = c;
        ans += w;
    }

    cout << ans << endl;
    cout << a << endl;

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