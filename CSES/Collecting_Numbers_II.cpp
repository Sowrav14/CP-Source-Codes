#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, q; cin >> n >> q;
    vector<int>v(n+10), ind(n+10);
    ind[0] = 0, ind[n+1] = n+1; v[0] = 0, v[n+1] = n + 1;
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        ind[v[i]] = i;
    }

    int ans = 1;
    for(int i=1;i<=n;i++){
        if(ind[i+1] < ind[i]) ans++;
    }
    while(q--){
        int x, y; cin >> x >> y;
        int vx = v[x], vy = v[y];
        if(vx > vy) swap(vx, vy);
        // for x
        if(ind[vx] < ind[vx-1]) ans--;
        if(ind[vx+1] < ind[vx]) ans--;
        // for y
        if(vx != vy-1 and ind[vy] < ind[vy-1]) ans--;
        if(ind[vy+1] < ind[vy]) ans--;
        // cout << vx << " " << vy << " " << ans << endl;
        swap(ind[vx], ind[vy]);
        swap(v[x], v[y]);
        // for x
        if(ind[vx] < ind[vx-1]) ans++;
        if(ind[vx+1] < ind[vx]) ans++;
        // for y
        if(vx != vy-1 and ind[vy] < ind[vy-1]) ans++;
        if(ind[vy+1] < ind[vy]) ans++;
        // swap(ind[vx], ind[vy]);
        
        cout << ans << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}