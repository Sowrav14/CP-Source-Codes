#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,s;
int c[55];
int h[55];
int dp[55][1005];


void solve(){

    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> c[i] >> h[i];
    }

    memset(dp, 0, sizeof(dp));

    for(int i=2;i<=n;i++){
        
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