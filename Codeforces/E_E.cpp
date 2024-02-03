#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e12;
int n,m,k;
int a[310][310];

void warshall(){
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}


void solve(){

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = (i==j) ? 0 : inf;
        }
    }

    for(int i=1;i<=m;i++){
        int x,y,w; cin >> x >> y >> w;
        a[x][y] = a[y][x] = w;
    }
    warshall();
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                a[i][j] = 0;
            }else if(a[i][j] <= k){
                a[i][j] = 1;
            } else{
                a[i][j] = inf;
            }
        }
    }

    warshall();


    int q; cin >> q;
    while(q--){
        int x,y; cin >> x >> y;
        if(a[x][y] >= inf){
            cout << -1 << endl;
        } else {
            cout << a[x][y] - 1 << endl;
        }
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