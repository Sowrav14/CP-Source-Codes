#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    char a[n][m];
    int vis[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            vis[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i][0] == '1'){
            int j = 0;
            while(j<m and a[i][j] == '1'){
                vis[i][j] = 1;
                j++;
            }
        }
    }
    for(int j=0;j<m;j++){
        if(a[0][j] == '1'){
            int i = 0;
            while(i<n and a[i][j] == '1'){
                vis[i][j] = 1;
                i++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '1'){
                if(!vis[i][j]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;

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