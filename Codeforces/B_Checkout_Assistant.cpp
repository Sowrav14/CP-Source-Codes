#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int>t,c;
int dp[2010][2001];
const int inf = 1e18;

int recur(int i, int time){
    if(time >= n) return 0;
    if(i == n) return inf;
    if(dp[i][time] != -1) return dp[i][time];
    int ans = inf;
    ans = min(ans, c[i]+recur(i+1, time+t[i]+1));
    ans = min(ans, recur(i+1, time));
    return dp[i][time] = ans;
}



void solve(){

    memset(dp, -1, sizeof(dp));
    cin >> n;
    t.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++){
        cin >> t[i] >> c[i];
    }
    cout << recur(0, 0) << endl;

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