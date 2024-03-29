#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,k; cin >> n >> k;
    char a[n][n];
    int dp[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == '#'){
                continue;
            }

            int y = 0;
            for(int k=j;k<n;k++){
                if(a[i][k] == '.'){
                    y++;
                } else{
                    break;
                }
            }
            if(y >= k){
                y = k;
                for(int k=j;k<n;k++){
                    dp[i][k]++;
                    y--;
                    if(y == 0){
                        break;
                    }
                }
            }

            int x = 0;
            for(int k=i;k<n;k++){
                if(a[k][j] == '.'){
                    x++;
                } else{
                    break;
                }
            }
            if(x >= k){
                x = k;
                for(int k=i;k<n;k++){
                    dp[k][j]++;
                    x--;
                    if(x == 0){
                        break;
                    }
                }
            }
        }
    }

    int ans = 0;
    int x = 0, y = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] > ans){
                ans = dp[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << x+1 << " " << y+1 << endl;

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