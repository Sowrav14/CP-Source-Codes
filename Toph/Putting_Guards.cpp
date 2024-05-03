#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int r,c; cin >> r >> c;
    int grid[r][c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j] != 1) continue;

            int one = 0, zero  = 0;;
            if(i-1 >= 0) grid[i-1][j] ? one++ : zero++;
            if(i+1 < r) grid[i+1][j] ? one++ : zero++;
            if(j+1 < c) grid[i][j+1] ? one++ : zero++;
            if(j-1 >= 0) grid[i][j-1] ? one++ : zero++;

            if(){
                
            }
        }
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