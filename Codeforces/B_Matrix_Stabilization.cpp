#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,m; cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x = a[i][j];
            int y = INT_MIN;
            if(i-1 >= 0) y = max(y, a[i-1][j]);
            if(j-1 >= 0) y = max(y, a[i][j-1]);
            if(i+1 < n) y = max(y, a[i+1][j]);
            if(j+1 < m) y = max(y, a[i][j+1]);

            a[i][j] = min(x, y);
            cout << a[i][j] << " ";
        } cout << endl;
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