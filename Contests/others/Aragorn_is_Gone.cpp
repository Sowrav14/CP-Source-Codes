#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 100 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int>v;
int k;
int n;

int dp[100][100][100];
int recur(int i, int tot, int sum){
    if(i == n){
        // cout << tot << " " << sum << endl;
        if(sum == 0 and tot == k) return 1;
        else return 0;
    }
    if(dp[i][tot][sum] != -1) return dp[i][tot][sum];

    int ans = 0;
    ans += recur(i+1, tot+1, (sum%k + v[i]%k)%k);
    ans += recur(i+1, tot, sum%k);

    return dp[i][tot][sum]=ans;
}


void solve(){

    cin >> n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int ans = 0;
    k = n;
    memset(dp, -1, sizeof(dp));
    cout << recur(0, 0, 0) << endl;
    for(int i=1;i<=n;i++){
        memset(dp, -1, sizeof(dp));
        k = i;
        ans += recur(0, 0, 0);
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        solve();
    }
}