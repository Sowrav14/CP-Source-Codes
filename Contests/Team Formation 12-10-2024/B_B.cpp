#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int>a;
int dp[N][2];

int recur(int i,int f){
    if(i == n-1){
        if(f) return a[i];
        else return 0;
    }
    if(dp[i][f] != -1) return dp[i][f];
    int ans = 0;
    if(f) {
        ans = a[i] | recur(i+1, f);
    } else {
        ans = max(ans, recur(i+1, 1));
        ans = max(ans, (a[i] | recur(i+1, f)));
    }
    return dp[i][f] = ans;
}

void solve(){

    cin >> n;
    a.clear();
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    cout << recur(0, 0) << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}