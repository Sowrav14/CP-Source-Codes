#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


char a[7][7];

void solve(){

    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            if(a[i][j] == 'W') continue;
            int flag = 1;
            if(a[i-1][j-1] == 'W') flag &= 0;
            if(a[i-1][j+1] == 'W') flag &= 0;
            if(a[i+1][j-1] == 'W') flag &= 0;
            if(a[i+1][j+1] == 'W') flag &= 0;

            if(flag){
                a[i][j] = 'W';
                ans++;
            }
        }
    }
    cout << ans << endl;

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