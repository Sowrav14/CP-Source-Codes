#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int>a;
int dp[N][3];

int recur(int i, int f){
    if(i == n) return 0;
    if(dp[i][f] != -1) return dp[i][f];
    int ans = 0;
    if(f == 0){
        ans = max(ans, abs(a[i]) + recur(i+1, 0));
        ans = max(ans, a[i]*2 + recur(i+1, 1));
    } else if(f == 1){
        ans = max(ans, a[i]*2 + recur(i+1, 1));
        ans = max(ans, abs(a[i]) + recur(i+1, 2));
    } else {
        ans = max(ans, abs(a[i]) + recur(i+1, 2));
    }
    return dp[i][f] = ans;
}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(0, 0) << endl;
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