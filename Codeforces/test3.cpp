#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int dp[200][200];
int n;
vector<int>v;
int recur(int i, int l){
    if(i == n+1){
        return 1;
    }
    if(dp[i][l] != -1) return dp[i][l];
    int ans = 0;
    ans += recur(i+1, l);
    if(v[i] > v[l]) ans += recur(i+1, i);
    return dp[i][l] = ans;
}



void solve(){

    memset(dp, -1, sizeof(dp));
    cin >> n;
    v.resize(n+1);
    v[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }

    cout << recur(1,0) << endl;

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