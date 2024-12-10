#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 100+10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int>a;
int dp[N][N*N][4];
int recur(int i, int sum,int cnt){
    if(i == n){
        if(sum == 0 and cnt == 3) return 1;
        else return 0;
    }
    if(i == n-1){
        return recur(n, sum, min(cnt+1, 3ll));
    }
    if(dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
    int ans = 0;
    if(cnt == 0){
        // take the current as minimum...
        ans += recur(i+1, sum, cnt+1);
        ans += recur(i+1, sum, cnt);
        // skip
    } else if(cnt == 1){
        // minimum is already taken...
        ans += recur(i+1, sum+a[i], cnt+1);
        ans += recur(i+1, sum, cnt);
        // skip
    } else {
        // you can finish here... 
        ans += recur(n, sum, min(cnt+1, 3ll));
        ans += recur(i+1, sum+a[i], min(cnt+1, 3ll));
        ans += recur(i+1, sum, cnt);
    }
    ans %= M;
    return dp[i][sum][cnt] = ans;
}


void solve(){

    int x; cin >> n >> x;
    for(int i=0;i<n;i++){
        int e; cin >> e;
        e -= x;
        a.push_back(e);
    }
    sort(a.begin(), a.end());
    memset(dp, -1, sizeof(dp));
    cout << recur(0, 0, 0) << endl;
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