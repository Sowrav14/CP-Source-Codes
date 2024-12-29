#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

map<pair<int,int>, double>dp;

double recur(int n, int p){
    pair<int,int> x = {n, p};
    if(n == 0) return dp[x] = 0;
    if(p == 0) return dp[x] = -n;
    if(n <= p) return dp[x] = p;
    if(dp.count(x) != 0) return dp[x];

    double less = (n - p) / (n * 1.0);
    double large = p / (n * 1.0);

    double ans = 0;
    ans += less * recur(n-1, p-1);
    ans += large * recur(n-1, p);

    return dp[x] = ans;
}


void solve(){

    int n; cin >> n;
    for(int i=n;i>=0;i--){
        recur(n, i);
    }
    // recur(3, 2);
    // for(auto i : dp){
    //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    // }
    for(int p=0;p<=n;p++){
        pair<int,int> x = {n, p};
        cout << fixed << setprecision(10) << dp[x] << " \n"[p == n];
    }

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